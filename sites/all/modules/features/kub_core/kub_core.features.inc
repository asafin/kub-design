<?php
/**
 * @file
 * kub_core.features.inc
 */

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function kub_core_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  return $custom_date_formats;
}

/**
 * Implements hook_fe_date_locale_date_format().
 */
function kub_core_fe_date_locale_date_format() {
  $locale_date_formats = array();

  // Exported format: long::en
  $locale_date_formats['long::en'] = array(
    'type' => 'long',
    'format' => 'l, F j, Y - H:i',
    'locales' => array(
      0 => 'en',
    ),
  );
  // Exported format: medium::en
  $locale_date_formats['medium::en'] = array(
    'type' => 'medium',
    'format' => 'D, m/d/Y - H:i',
    'locales' => array(
      0 => 'en',
    ),
  );
  // Exported format: short::en
  $locale_date_formats['short::en'] = array(
    'type' => 'short',
    'format' => 'd.m.Y - H:i',
    'locales' => array(
      0 => 'en',
    ),
  );
  return $locale_date_formats;
}
