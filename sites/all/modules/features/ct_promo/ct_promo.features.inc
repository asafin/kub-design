<?php
/**
 * @file
 * ct_promo.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ct_promo_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function ct_promo_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: carousel
  $nodequeues['carousel'] = array(
    'name' => 'carousel',
    'title' => 'Carousel',
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
      0 => 'promo',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_node_info().
 */
function ct_promo_node_info() {
  $items = array(
    'promo' => array(
      'name' => t('Промо'),
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
