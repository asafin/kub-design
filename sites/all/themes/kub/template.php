<?php

/**
 * @file keeps theming and preprocess functions overrides
 */


/**
 * Preprocess template html.tpl.php
 *
 */
function kub_preprocess_html(&$variables) {
  drupal_add_css('https://fonts.googleapis.com/css?family=PT+Sans+Narrow:400,700&subset=latin,cyrillic-ext,cyrillic', array(
    'type' => 'external',
    'group' => CSS_SYSTEM,
  ));
  drupal_add_js(drupal_get_path('theme', 'kub') . '/js/bootstrap.js');

  $path = base_path();

  drupal_add_html_head(array(
    '#tag' => 'link',
    '#attributes' => array(
      'href' => $path . drupal_get_path('theme', 'kub') . '/favicon.jpg',
      'rel' => 'shortcut icon',
      'type' => 'image/x-icon'
    ),
  ), 'favicon-ico');
}

/**
 * Implements hook_html_head_alter().
 */
function kub_html_head_alter(&$head_elements) {
  unset($head_elements['metatag_shortcut icon']);
}

/**
 * Implements hook_theme()
 */
function kub_theme() {
  $items = array();
  $items['layout_header'] = array(
    'variables' => array(),
    'template' => 'templates/layout/layout-header',
  );
  $items['layout_content'] = array(
    'variables' => array(),
    'template' => 'templates/layout/layout-content',
  );
  $items['layout_footer'] = array(
    'variables' => array(),
    'template' => 'templates/layout/layout-footer',
  );
  $items['layout_sidebar'] = array(
    'variables' => array(),
    'template' => 'templates/layout/layout-sidebar',
  );
  return $items;
}

/**
 * Preprocess template page.tpl.php
 *
 * @param $variables
 *
 * @throws Exception
 */
function kub_preprocess_page(&$variables) {
  $variables['header'] = theme('layout_header');
  $variables['content'] = theme('layout_content', array(
    'page' => $variables['page'],
  ));
  $variables['footer'] = theme('layout_footer');
}

/**
 * Preprocess template layout-header.tpl.php
 *
 * @param $variables
 */
function kub_preprocess_layout_header(&$variables) {
  $variables['logo'] = '<div class="logo">' . l(t('Home'), '<front>') . '</div>';
  $variables['header_phone'] = variable_get("site_phone");

  $variables['home_link'] = l(
    "<i class='glyphicon glyphicon-home'></i>",
    '/',
    array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array('navbar-brand')
      )
    )
  );
  $variables['navigation'] = theme('links__header_navigation', [
    'menu_name' => 'main-menu',
  ]);
}

/**
 * Preprocess template layout-content.tpl.php
 *
 * @param $variables
 *
 * @throws Exception
 */
function kub_preprocess_layout_content(&$variables) {
  $variables['content_attributes_array']['class']['content'] = 'content';

  $variables['messages'] = theme('status_messages');

  if (!drupal_is_front_page()) {
    $variables['breadcrumb'] = theme('breadcrumb', [
      'breadcrumb' => drupal_get_breadcrumb(),
    ]);
  }

  $variables['tabs'] = theme('menu_local_tasks', array(
    'primary' => menu_primary_local_tasks(),
    'secondary' => menu_secondary_local_tasks(),
  ));
  if(!drupal_is_front_page()){
    $variables['title'] = drupal_get_title();
  }
  $variables['help'] = menu_get_active_help();

  $url_base_raw = explode('/', drupal_get_path_alias());
  $url_base = $url_base_raw[0];

  if($url_base == 'maps'){
    $variables['content_attributes_array']['class']['col-lg-12'] = 'col-lg-12';
    $variables['content_attributes_array']['class']['col-md-12'] = 'col-md-12';
    $variables['content_attributes_array']['class']['col-sm-12'] = 'col-sm-12';
    $variables['content_attributes_array']['class']['col-xs-12'] = 'col-xs-12';
  }else{
    $variables['content_attributes_array']['class']['col-lg-8'] = 'col-lg-8';
    $variables['content_attributes_array']['class']['col-md-8'] = 'col-md-8';
    $variables['content_attributes_array']['class']['col-sm-8'] = 'col-sm-8';
    $variables['content_attributes_array']['class']['col-xs-12'] = 'col-xs-12';

    $variables['sidebar'] = theme('layout_sidebar');
  }
}

/**
 * Process template layout-content.tpl.php
 *
 * @param $variables
 *
 * @throws Exception
 */
function kub_process_layout_content(&$variables) {
  $variables['content_attributes'] = drupal_attributes($variables['content_attributes_array']);
}

/**
 * Preprocess template layout-sidebar.tpl.php
 *
 * @param $variables
 *
 * @throws Exception
 */
function kub_preprocess_layout_sidebar(&$variables) {
  $url_base_alias = drupal_get_path_alias();
  $url_base_raw = explode('/', $url_base_alias);
  $url_base = $url_base_raw[0];

  $sidebar_banner_row = views_get_view_result('sidebar_banner');
  if (!empty($sidebar_banner_row) && !empty($sidebar_banner_row[0]->field_field_promo_link)){
    $sidebar_banner_url = $sidebar_banner_row[0]->field_field_promo_link[0]['raw']['url'];
    if($sidebar_banner_url != $url_base_alias){
      $variables['sidebar_banner'] = views_embed_view('sidebar_banner', 'default');
    }
  }

  if ($url_base != 'tweets'){
    $variables['sidebar_tweets'] = theme('core_news_block', [
      'header' => 'Твиты',
      'content' => views_embed_view('tweets_page', 'block_tweets'),
    ]);
  }

  if ($url_base != 'blog'){
    $variables['sidebar_blog'] = theme('core_news_block', [
      'header' => 'Блог',
      'content' => views_embed_view('blog_page', 'block_blog'),
    ]);
  }

  if ($url_base != 'news'){
    $variables['sidebar_news'] = theme('core_news_block', [
      'header' => 'Новости',
      'content' => views_embed_view('news_page', 'block_news'),
    ]);
  }

  if(arg(0) == 'taxonomy' && !empty(arg(2)) && is_numeric(arg(2))){
    if(!empty(taxonomy_term_load(arg(2)))) {
      $term = taxonomy_term_load(arg(2));
      if($term->vocabulary_machine_name == 'specializations'){
        $variables['specializations_tags'] = theme('core_news_block', [
          'header' => 'Отрасли',
          'content' => views_embed_view('specializations_tags_block', 'specializations_tags_title_block'),
        ]);

        $variables['sidebar_segments'] = theme('core_news_block', [
          'header' => 'Сегменты',
          'content' => views_embed_view('segment_block', 'default', arg(2)),
        ]);
      }
    }
  }

  if ($url_base == 'products' || $url_base == 'functional-units'){
    $variables['specializations_tags'] = theme('core_news_block', [
      'header' => 'Отрасли',
      'content' => views_embed_view('specializations_tags_block', 'specializations_tags_title_block'),
    ]);
  }
}

/**
 * Preprocess template layout-footer.tpl.php
 *
 * @param $variables
 */
function kub_preprocess_layout_footer(&$variables) {
  $variables['site_slogan'] = variable_get('site_slogan');
  $variables['site_copyright'] = format_text_variable_get("site_copyright");
  $variables['footer_message'] = format_text_variable_get('footer_message');
  $variables['footer_email'] = l(variable_get('site_mail'), 'mailto:' . variable_get('site_mail'));
  $variables['sitemap_link'] = l('Карта сайта', 'sitemap');
}

/**
 * Theme main menu
 *
 * @param $variables
 *
 * @throws Exception
 * @return string
 */
function kub_links__header_navigation($variables) {
  $output = '';
  if (!empty($variables['menu_name'])) {
    $variables['tree'] = menu_tree_page_data($variables['menu_name']);
    $output .= '<ul class="nav navbar-nav sidebar-menu menu--' . $variables['menu_name'] . '">';
  }

  foreach ($variables['tree'] as $item) {
    if (!$item['link']['hidden']) {
      $class = ['menu-' . $item['link']['mlid']];
      if (!empty($item['link']['localized_options'])) {
        $l = $item['link']['localized_options'];
      }
      else {
        $l = [];
      }

      $l['href'] = $item['link']['href'];

      $l['title'] = $item['link']['title'];
      if ($item['link']['in_active_trail']) {
        $class[] = 'active';
      }

      $output .= '<li class="' . implode(' ', $class) . '">' . l($l['title'], $l['href'], $l) . '</li>';
    }
  }

  $output .= '</ul>';

  return $output;
}

/**
 * Implements hook_form_alter
 *
 * @param $form
 */
function kub_form_alter(&$form){
  if (!empty($form['#node']->type) && $form['#node']->type == 'webform'){
    $form['actions']['submit']['#attributes']['class'] = [
      'btn' => 'btn',
      'btn-default' => 'btn-default',
    ];
  }
}

/**
 * Overrides theme_breadcrumb()
 *
 * @see theme_breadcrumb()
 *
 * @param $variables
 *
 * @return string
 */
function kub_breadcrumb($variables) {
  $output = '';
  $breadcrumb = $variables['breadcrumb'];
  if (!empty($breadcrumb)) {
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $output .= '<ol class="breadcrumb">';
    foreach ($breadcrumb as $i => $value) {
      if ($i == 0) {
        $title = '<i class="glyphicon glyphicon-home"></i>' . t('Главная');
        $output .= '<li>' . l($title, '<front>', ['html' => TRUE]) . '</li>';

        if(!empty(arg(1)) && is_numeric(arg(1))){
          if(!empty(node_load(arg(1)))){
            $node = node_load(arg(1));
            switch ($node->type) {
              case 'tweet':
                $output .= '<li>' . l('Твиты', 'tweets') . '</li>';
                break;
              case 'news':
                $output .= '<li>' . l('Новости', 'news') . '</li>';
                break;
              case 'client':
                $output .= '<li>' . l('Клиенты', 'clients') . '</li>';
                break;
              case 'support':
                $output .= '<li>' . l('Обучение', 'support') . '</li>';
                break;
              case 'equipment':
                $output .= '<li>' . l('Оборудование', 'equipments') . '</li>';
                $tid = $node->field_equipment_tag['und'][0]['tid'];
                $term = taxonomy_term_load($tid);
                $output .= '<li>' . l($term->name, 'taxonomy/term/' . $tid) . '</li>';
                break;
              case 'product':
                $output .= '<li>' . l('Продукты', 'products') . '</li>';
                break;
              case 'unit':
                $output .= '<li>' . l('Продукты', 'products') . '</li>';
                break;
              case 'segment':
                $output .= '<li>' . l('Продукты', 'products') . '</li>';
                break;
              case 'map':
                $output .= '<li>' . l('Продукты', 'products') . '</li>';
                break;
            }
          }
        }
      }else {
        $output .= '<li>' . $value . '</li>';
      }
    }
    $output .= '</ol>';
  }

  return $output;
}

/**
 * Menu local tasks theme
 *
 * @param $variables
 * @return string
 */
function kub_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables ['primary'])) {
    $variables ['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables ['primary']['#prefix'] .= '<ul class="nav nav-tabs">';
    $variables ['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables ['primary']);
  }
  if (!empty($variables ['secondary'])) {
    $variables ['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables ['secondary']['#prefix'] .= '<ul class="nav nav-tabs">';
    $variables ['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables ['secondary']);
  }

  return $output;
}

/**
 * Preprocess function for theme_field()
 *
 * @see template_preprocess_field()
 * @see theme_field()
 *
 * @param $variables
 */
function kub_preprocess_field(&$variables) {
  $element = &$variables['element'];

  if ($element['#field_type'] == 'image'){
    if(in_array($element['#formatter'], ['fancybox', 'image'])) {
      foreach ($variables['items'] as &$item) {
        $item['#item']['attributes'] = [
          'class' => [
            'thumbnail' => 'img-thumbnail',
          ],
        ];
      }
    }
    if($element[0]['#image_style'] == 'specialization_medium'){
      foreach ($variables['items'] as &$item) {
        $item['#item']['attributes'] = [
          'class' => [
            'responsive' => 'img-responsive',
            'thumbnail' => 'img-thumbnail',
          ],
        ];
      }
    }
  }

  if ($element['#field_name'] == 'field_news_link') {
    foreach ($variables['items'] as &$item) {
      $item['#element']['attributes']['class'] = 'btn btn-info';
    }
  }

  _kub_preprocess_field_prefix_icon($element, $variables['items']);
}

/**
 * Helper function. Prefixes field with an icon.
 *
 * @param array $element
 * @param array $items
 */
function _kub_preprocess_field_prefix_icon($element, &$items) {
  $list = _kub_preprocess_fields_prefix_icons_list();
  if (!empty($list[$element['#field_name']])) {
    foreach ($items as &$item) {
      $item['#prefix'] = '<i class="' . $list[$element['#field_name']] . ' glyphicon"></i>';
    }
  }
}

/**
 * Helper function. Returns list of fields that should be prefixed with icons.
 *
 * @return array
 */
function _kub_preprocess_fields_prefix_icons_list() {
  return [
    'field_blog_date' => 'glyphicon-calendar',
    'field_blog_tags' => 'glyphicon-tags',
    'field_news_date' => 'glyphicon-calendar',
    'field_news_tags' => 'glyphicon-tags',
    'field_tweet_date' => 'glyphicon-calendar',
    'field_support_date' => 'glyphicon-calendar',
    'field_product_units' => 'glyphicon-play',
    'field_segment_tag' => 'glyphicon-tags',
  ];
}

/**
 * Preprocess function for node.tpl.php
 *
 * @see template_preprocess_node()
 *
 * @param $variables
 */
function kub_preprocess_node(&$variables) {
  $content = &$variables['content'];

  if ($variables['view_mode'] == 'teaser') {
    $variables['theme_hook_suggestions'][] = 'node__' . $variables['node']->type . '__teaser';
    $variables['theme_hook_suggestions'][] = 'node__' . $variables['node']->nid . '__teaser';

    if(!empty($content['links']['node']['#links']['node-readmore'])){
      $content['links']['node']['#links']['node-readmore']['attributes']['class']['btn'] = 'btn';
      $content['links']['node']['#links']['node-readmore']['attributes']['class']['btn-default'] = 'btn-default';
      $variables['content']['links']['node']['#links']['node-readmore']['title'] = 'Подробнее';
    }
  }

  if ($variables['node']->type == 'blog') {
    if (!empty($content['field_blog_images'])) {
      $content['field_blog_first_image'] = $content['field_blog_images'];
      $content['field_blog_first_image'][0]['#settings']['preview'] = "kub_medium";
      $size = sizeof($content['field_blog_images']['#items']);
      if ($size > 1) {
        unset($content['field_blog_images']['#items'][0]);
        for ($i = 1; $i < $size; $i++) {
          unset($content['field_blog_first_image'][$i]);
        }
      }else{
        unset($content['field_blog_images']);
      }
      $content['field_blog_first_image']['#field_name'] = 'field_blog_first_image';
      $content['field_blog_first_image']['#weight'] = $content['field_blog_date']['#weight'];
      $content['field_blog_date']['#weight'] = $content['field_blog_date']['#weight'] -1;
    }
  }

  if ($variables['node']->type == 'news') {
    if (!empty($content['field_news_image'])) {
      $content['field_news_first_image'] = $content['field_news_image'];
      $content['field_news_first_image'][0]['#settings']['preview'] = "news_medium";
      $size = sizeof($content['field_news_image']['#items']);
      if ($size > 1) {
        unset($content['field_news_image']['#items'][0]);
        for ($i = 1; $i < $size; $i++) {
          unset($content['field_news_first_image'][$i]);
        }
      }else{
        unset($content['field_news_image']);
      }

      $content['field_news_first_image']['#field_name'] = 'field_news_first_image';
      $content['field_news_first_image']['#weight'] = $content['field_news_date']['#weight'];
      $content['field_news_date']['#weight'] = $content['field_news_date']['#weight'] -1;
    }
  }

  if ($variables['node']->type == 'product') {
    if(!empty($content['field_product_units'])){
      $content['context']['field_product_units'] = $content['field_product_units'];
      unset($content['field_product_units']);
    }
  }

  if ($variables['node']->type == 'map') {
    $content['map_info_blocks'] = views_embed_view('map_info_blocks', 'default', $variables['vid']);
    $content['map_areas'] = views_embed_view('map_areas', 'default', $variables['vid']);

    if(!empty($variables['field_map_image_url'][0]['uri'])){
      $img_vars = [
        'path' => $variables['field_map_image_url'][0]['uri'],
        'attributes' => [
          'usemap' => '#tsMap',
        ],
      ];
      $content['map_img'] = theme_image($img_vars);
    }
    $content['map_menu_block'] = views_embed_view('maps_menu_block', 'default');
  }

  if ($variables['node']->type == 'page' && $variables['field_page_alias']['und'][0]['value'] == 'service-center') {
    $service_center_first_button_url = variable_get('service_center_first_button_url');
    $service_center_second_button_url = variable_get('service_center_second_button_url');
    $attributes = [
      'attributes' => [
        'class' => ['btn', 'btn-default']
      ],
    ];

    if(!empty($service_center_first_button_url)){
      $variables['content']['service_center_first_button'] = [
        '#prefix' => '<div class="service-center-button">',
        '#suffix' => '</div>',
        '#weight' => 1,
        '#markup' => l(variable_get('service_center_first_button_text'), $service_center_first_button_url,  $attributes),
      ];
    }

    if(!empty($service_center_second_button_url)){
      $variables['content']['service_center_second_button'] = [
        '#prefix' => '<div class="service-center-button">',
        '#suffix' => '</div>',
        '#weight' => 2,
        '#markup' => l(variable_get('service_center_second_button_text'), $service_center_second_button_url,  $attributes),
      ];
    }
  }
}

/**
 * @see template_preprocess_views_view_field()
 *
 * @param $variables
 */
function kub_preprocess_views_view_field(&$variables) {
  if (!empty($variables['view']->name) && $variables['view']->name == 'support_page') {
    if ($variables['field']->field == 'view_node') {
      $nid = $variables['row']->nid;
      $variables['output'] = l('Подробнее', 'node/' . $nid, array('attributes' => array('class' => array('btn', 'btn-default'))));
    }
  }
}

/**
 * Preprocess function for theme_captcha().
 */
function kub_preprocess_captcha(&$variables) {
  if ($variables['element']['#captcha_type'] == 'image_captcha/Image' && isset($variables['element']['captcha_widgets'])) {
    $variables['element']['captcha_widgets']['captcha_response']['#field_prefix'] = drupal_render($variables['element']['captcha_widgets']['captcha_image']);
    $variables['element']['captcha_widgets']['captcha_image']['#access'] = FALSE;
  }
}
