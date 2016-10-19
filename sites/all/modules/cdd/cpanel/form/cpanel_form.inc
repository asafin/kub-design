<?php

/**
 * @file keeps cpanel_form callbacks
 */

/**
 * Form builder callback for cpanel_form
 *
 * @param $form
 * @param $form_state
 *
 * @return array
 */
function cpanel_form($form, &$form_state) {
  module_load_include("inc", "cpanel", "form/cpanel_form/system");
  module_load_include("inc", "cpanel", "form/cpanel_form/user");

  $form["settings"] = [
    "#type" => "item",
    "#title" => t("General settings"),
    "#weight" => 0,
  ];

  cpanel_form_system($form, $form_state);
  cpanel_form_user($form, $form_state);

  drupal_alter("cpanel", $form, $form_state);

  return system_settings_form($form);
}

/**
 * Validation callback for cpanel_form
 *
 * @param $form
 * @param $form_state
 */
function cpanel_form_validate($form, &$form_state) {
}

/**
 * Submission callback for cpanel_form
 *
 * @param $form
 * @param $form_state
 */
function cpanel_form_submit($form, &$form_state) {
}
