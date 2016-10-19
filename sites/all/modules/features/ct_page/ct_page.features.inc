<?php
/**
 * @file
 * ct_page.features.inc
 */

/**
 * Implements hook_node_info().
 */
function ct_page_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Статическая страница'),
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
