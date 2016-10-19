<?php
/**
 * @file
 * ct_file.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ct_file_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ct_file_node_info() {
  $items = array(
    'file' => array(
      'name' => t('Файл'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
