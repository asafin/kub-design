<?php
/**
 * @file
 * ct_gallery.features.inc
 */

/**
 * Implements hook_node_info().
 */
function ct_gallery_node_info() {
  $items = array(
    'gallery' => array(
      'name' => t('Галерея работ'),
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
