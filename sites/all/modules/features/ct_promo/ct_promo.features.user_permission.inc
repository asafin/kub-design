<?php
/**
 * @file
 * ct_promo.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ct_promo_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create promo content'.
  $permissions['create promo content'] = array(
    'name' => 'create promo content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any promo content'.
  $permissions['delete any promo content'] = array(
    'name' => 'delete any promo content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own promo content'.
  $permissions['delete own promo content'] = array(
    'name' => 'delete own promo content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any promo content'.
  $permissions['edit any promo content'] = array(
    'name' => 'edit any promo content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own promo content'.
  $permissions['edit own promo content'] = array(
    'name' => 'edit own promo content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
