<?php

/**
 * @file keeps Menu module alterations
 */

/**
 * Helper for hook_menu_alter(): alters Menu module paths.
 *
 * @param $items
 */
function cpanel_menu_alter_menu(&$items) {
  $items["admin/structure/menu"]["page callback"] = "cpanel_menu_overview_page";
  $items["admin/structure/menu"]["access callback"] = "cpanel_access_menu";

  $access_callback = "cpanel_access_menu";
  $access_arguments = ["administer menu", 4];

  $items["admin/structure/menu/manage/%menu"]["access callback"] = $access_callback;
  $items["admin/structure/menu/manage/%menu"]["access arguments"] = $access_arguments;

  $items["admin/structure/menu/manage/%menu/list"]["access callback"] = $access_callback;
  $items["admin/structure/menu/manage/%menu/list"]["access arguments"] = $access_arguments;

  $items["admin/structure/menu/manage/%menu/add"]["access callback"] = $access_callback;
  $items["admin/structure/menu/manage/%menu/add"]["access arguments"] = $access_arguments;

  $items["admin/structure/menu/manage/%menu/edit"]["access callback"] = $access_callback;
  $items["admin/structure/menu/manage/%menu/edit"]["access arguments"] = $access_arguments;

  $access_callback = "cpanel_access_menu_link";

  $items["admin/structure/menu/item/%menu_link/edit"]["access callback"] = $access_callback;
  $items["admin/structure/menu/item/%menu_link/edit"]["access arguments"] = $access_arguments;

  $items["admin/structure/menu/item/%menu_link/reset"]["access callback"] = $access_callback;
  $items["admin/structure/menu/item/%menu_link/reset"]["access arguments"] = $access_arguments;

  $items["admin/structure/menu/item/%menu_link/delete"]["access callback"] = $access_callback;
  $items["admin/structure/menu/item/%menu_link/delete"]["access arguments"] = $access_arguments;
}

/**
 * Implements hook_form_FORM_ID_alter for menu_edit_item
 *
 * @param $form
 */
function cpanel_form_menu_edit_item_alter(&$form) {
  $menus = menu_get_menus();
  foreach ($menus as $name => $title) {
    if (!cpanel_access_menu("administer menu", ["menu_name" => $name])) {
      unset($menus[$name]);
    }
  }
  $form["parent"]["#options"] = menu_parent_options($menus, $form["original_item"]["#value"]);
}

/**
 * Helper to implement hook_form_BASE_FORM_ID_alter for node_form: alters Menu module settings
 *
 * @param $form
 */
function cpanel_form_node_form_alter_menu(&$form) {
  $link = $form["#node"]->menu;
  $type = $form["#node"]->type;
  if ($form["menu"]["#access"] = cpanel_access_menu("administer menu", ["menu_name" => $link["menu_name"]])) {
    $menus = menu_get_menus();
    foreach ($menus as $name => $title) {
      if (!cpanel_access_menu("administer menu", ["menu_name" => $name])) {
        unset($menus[$name]);
      }
    }
    $form["menu"]["link"]["parent"]["#options"] = menu_parent_options($menus, $link["mlid"] ? $link : $type, $type);
  }
}

/**
 * Override of the menu_overview_page()
 *
 * @return string
 */
function cpanel_menu_overview_page() {
  $result = db_query("SELECT * FROM {menu_custom} ORDER BY title", [], [
    "fetch" => PDO::FETCH_ASSOC,
  ]);

  $rows = [];
  foreach ($result as $menu) {
    $row = [
      theme("menu_admin_overview", [
        "title" => $menu["title"],
        "name" => $menu["menu_name"],
        "description" => $menu["description"],
      ]),
    ];

    $row[] = ["data" => al(t("list links"), "admin/structure/menu/manage/" . $menu["menu_name"])];
    $row[] = ["data" => al(t("edit menu"), "admin/structure/menu/manage/" . $menu["menu_name"] . "/edit")];
    $row[] = ["data" => al(t("add link"), "admin/structure/menu/manage/" . $menu["menu_name"] . "/add")];

    $rows[] = $row;
  }

  return theme("table", [
    "header" => [
      t("Title"),
      ["data" => t("Operations"), "colspan" => "3"],
    ],
    "rows" => $rows,
  ]);
}

/**
 * Access callback for menu admin pages
 *
 * @param string $perm
 * @param null   $menu
 *
 * @return bool
 */
function cpanel_access_menu($perm = "administer menu", $menu = NULL) {
  $access = FALSE;

  if ($menu) {
    $access = (user_access($perm) || user_access("manage {$menu["menu_name"]} menu"));
  }
  else {
    $menus = menu_get_menus();
    foreach ($menus as $name => $title) {
      if ($access = user_access("manage $name menu")) {
        break;
      }
    }
  }

  return $access;
}

/**
 * Access callback for menu item admin pages
 *
 * @param $perm
 * @param $link
 *
 * @return bool
 */
function cpanel_access_menu_link($perm, $link) {
  return (user_access($perm) || user_access("manage {$link["menu_name"]} menu"));
}
