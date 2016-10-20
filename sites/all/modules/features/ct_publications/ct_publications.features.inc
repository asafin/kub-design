<?php
/**
 * @file
 * ct_publications.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ct_publications_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function ct_publications_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: publications
  $nodequeues['publications'] = array(
    'name' => 'publications',
    'title' => 'Publications',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'types' => array(
      0 => 'publication',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function ct_publications_node_info() {
  $items = array(
    'publication' => array(
      'name' => t('Публикация'),
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
