<?php

/**
 * @file Control panel field from System module
 */

/**
 * System module settings
 *
 * @param $form
 * @param $form_state
 */
function cpanel_form_system(&$form, &$form_state) {
  $form["system_settings"] = [
    "#type" => "vertical_tabs",
    "#weight" => 1,
  ];
  $form["site_information"] = [
    "#type" => "fieldset",
    "#title" => t("Site information"),
    "#group" => "system_settings",
  ];
  $form["site_information"]["site_name"] = [
    "#type" => "textfield",
    "#title" => t("Site name"),
    "#default_value" => variable_get("site_name", "Drupal"),
    "#required" => TRUE,
    "#weight" => -10,
  ];
  $form["site_information"]["site_slogan"] = [
    "#type" => "textfield",
    "#title" => t("Slogan"),
    "#default_value" => variable_get("site_slogan", ""),
    "#description" => t("How this is used depends on your site's theme."),
    "#weight" => -9,
  ];
  $form["site_information"]["site_mail"] = [
    "#type" => "textfield",
    "#title" => t("E-mail address"),
    "#default_value" => variable_get("site_mail", ini_get("sendmail_from")),
    "#description" => t("The <em>From</em> address in automated e-mails sent during registration and new password requests, and other notifications. (Use an address ending in your site's domain to help prevent this e-mail being flagged as spam.)"),
    "#required" => TRUE,
    "#weight" => -8,
  ];
}
