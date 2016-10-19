<?php
/**
 * @file
 * ct_faq.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ct_faq_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_faq_answer'.
  $field_bases['field_faq_answer'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_faq_answer',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  return $field_bases;
}