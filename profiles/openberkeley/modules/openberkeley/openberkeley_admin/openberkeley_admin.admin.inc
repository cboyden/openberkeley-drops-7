<?php
/**
 * Administer Open Berkeley Settings Page
 */
function openberkeley_admin_openberkeley_settings_page() {
  $item = menu_get_item('admin/config/openberkeley');
  if ($content = system_admin_menu_block($item)) {
    $output = theme('admin_block_content', array('content' => $content));
    // rewrite the url in order to return the user to the Open Berkeley tab on the dashboard.
    $output = preg_replace('/(admin\/config\/openberkeley\/[^"]+)/', "\\1" . '?destination=admin/dashboard/openberkeley', $output);
  }
  else {
    $output = t('You do not have any administrative items.');
  }

  return $output;
}

/**
 * Re-implement node_add_page
 *
 * @return string
 */
function openberkeley_admin_node_add_page() {
  $item = menu_get_item('node/add');
  $content = system_admin_menu_block($item);
  // Bypass the node/add listing if only one content type is available.
  if (count($content) == 1) {
    $item = array_shift($content);
    drupal_goto($item['href']);
  }

  return theme('node_add_list', array('content' => $content));
}
