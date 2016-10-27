<?php
/**
 * @file
 * ct_promo.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ct_promo_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'carousel';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Carousel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'carousel' => 'carousel',
    'faq' => 0,
    'publications' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Ссылка */
  $handler->display->display_options['fields']['field_promo_link']['id'] = 'field_promo_link';
  $handler->display->display_options['fields']['field_promo_link']['table'] = 'field_data_field_promo_link';
  $handler->display->display_options['fields']['field_promo_link']['field'] = 'field_promo_link';
  $handler->display->display_options['fields']['field_promo_link']['label'] = '';
  $handler->display->display_options['fields']['field_promo_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_link']['click_sort_column'] = 'url';
  /* Field: Content: Текст */
  $handler->display->display_options['fields']['field_promo_text']['id'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['table'] = 'field_data_field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['field'] = 'field_promo_text';
  $handler->display->display_options['fields']['field_promo_text']['label'] = '';
  $handler->display->display_options['fields']['field_promo_text']['element_label_colon'] = FALSE;
  /* Field: Content: Баннер */
  $handler->display->display_options['fields']['field_promo_image']['id'] = 'field_promo_image';
  $handler->display->display_options['fields']['field_promo_image']['table'] = 'field_data_field_promo_image';
  $handler->display->display_options['fields']['field_promo_image']['field'] = 'field_promo_image';
  $handler->display->display_options['fields']['field_promo_image']['label'] = '';
  $handler->display->display_options['fields']['field_promo_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_promo_image']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $translatables['carousel'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
  );
  $export['carousel'] = $view;

  return $export;
}
