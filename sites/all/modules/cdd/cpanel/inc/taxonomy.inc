<?php

/**
 * @file keeps Taxonomy module alterations
 */

/**
 * Helper for hook_menu_alter(): alters Taxonomy module paths.
 *
 * @param $items
 */
function cpanel_menu_alter_taxonomy(&$items) {
  $items["admin/structure/taxonomy"]["access arguments"] = ["access vocabularies list"];
  $items["admin/structure/taxonomy"]["page arguments"] = ["cpanel_taxonomy_overview_vocabularies"];
  $items["admin/structure/taxonomy/%taxonomy_vocabulary_machine_name"]["access callback"] = "cpanel_term_access";
  $items["admin/structure/taxonomy/%taxonomy_vocabulary_machine_name"]["access arguments"] = ["edit", 3];
  $items["admin/structure/taxonomy/%taxonomy_vocabulary_machine_name/add"]["access callback"] = "cpanel_term_access";
  $items["admin/structure/taxonomy/%taxonomy_vocabulary_machine_name/add"]["access arguments"] = ["add", 3];
}

/**
 * Access callback for taxonomy terms
 *
 * @param $operation
 * @param $vocabulary
 *
 * @return bool
 */
function cpanel_term_access($operation, $vocabulary) {
  if ($operation == "add") {
    $vocabulary_id = $vocabulary->machine_name;
  }
  else {
    $vocabulary_id = $vocabulary->vid;
  }
  return (
    user_access("$operation terms in $vocabulary_id")
    || user_access("administer taxonomy")
  );
}

/**
 * Page callback (form builder) for admin/structure/taxonomy page
 *
 * @param $form
 *
 * @return mixed
 */
function cpanel_taxonomy_overview_vocabularies($form) {
  $form = taxonomy_overview_vocabularies($form);
  $vocabularies = taxonomy_get_vocabularies();
  foreach ($vocabularies as $vocabulary) {
    $menu = menu_get_item($form[$vocabulary->vid]["edit"]["#href"]);
    !$menu["access"] ? $form[$vocabulary->vid]["edit"] = [] : TRUE;
    $menu = menu_get_item($form[$vocabulary->vid]["list"]["#href"]);
    !$menu["access"] ? $form[$vocabulary->vid]["list"] = [] : TRUE;
    $menu = menu_get_item($form[$vocabulary->vid]["add"]["#href"]);
    !$menu["access"] ? $form[$vocabulary->vid]["add"] = [] : TRUE;
  }
  if (!user_access("administer taxonomy")) {
    unset($form["actions"]["submit"]);
  }
  $form["#theme"] = "taxonomy_overview_vocabularies";
  $form["#submit"][] = "taxonomy_overview_vocabularies_submit";
  return $form;
}
