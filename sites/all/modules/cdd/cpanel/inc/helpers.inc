<?php

/**
 * @file keeps helper functions for faster adding Control panel elements
 */

/**
 * Helper to create text_format field faster
 *
 * @param        $var
 * @param        $title
 * @param string $desc
 * @param bool   $required
 * @param string $value
 * @param string $format
 *
 * @return array
 */
function cpanel_text_format_field($var, $title, $desc = "", $required = FALSE, $value = "", $format = "") {
  if ($format == "") {
    $format = variable_get("cpanel_textarea_format", variable_get("filter_fallback_format"));
  }
  $variable = variable_get($var, [
    "value" => $value,
    "format" => $format,
  ]);
  return [
    "#type" => "text_format",
    "#base_type" => "textarea",
    "#title" => t($title),
    "#description" => t($desc),
    "#default_value" => $variable["value"],
    "#format" => $variable["format"],
    "#required" => $required,
  ];
}

/**
 * Helper to create vertical tab group faster
 *
 * @param $title
 * @param $group
 *
 * @return array
 */
function cpanel_vertical_tab($title, $group) {
  return [
    "#type" => "fieldset",
    "#title" => t($title),
    "#group" => $group,
  ];
}
