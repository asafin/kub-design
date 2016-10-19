<?php
/**
 * @file
 * ct_file.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ct_file_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create file content'.
  $permissions['create file content'] = array(
    'name' => 'create file content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any file content'.
  $permissions['delete any file content'] = array(
    'name' => 'delete any file content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own file content'.
  $permissions['delete own file content'] = array(
    'name' => 'delete own file content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any file content'.
  $permissions['edit any file content'] = array(
    'name' => 'edit any file content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own file content'.
  $permissions['edit own file content'] = array(
    'name' => 'edit own file content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
