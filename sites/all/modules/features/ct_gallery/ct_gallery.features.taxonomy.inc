<?php
/**
 * @file
 * ct_gallery.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ct_gallery_taxonomy_default_vocabularies() {
  return array(
    'gallery' => array(
      'name' => 'Галерея работ',
      'machine_name' => 'gallery',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
