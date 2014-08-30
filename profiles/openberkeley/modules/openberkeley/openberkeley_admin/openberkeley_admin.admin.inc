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

function my_create_a_node() {
  global $user;
// entity_create replaces the procedural steps in the first example of
// creating a new object $node and setting its 'type' and uid property
  $values = array(
    'type' => 'openberkeley_content_page',
    'uid' => 1,
    'status' => 1,
    'comment' => 1,
    'promote' => 0,
  );
  $entity = entity_create('node', $values);
// The entity is now created, but we have not yet simplified use of it.
// Now create an entity_metadata_wrapper around the new node entity
// to make getting and setting values easier
  $ewrapper = entity_metadata_wrapper('node', $entity);
// Using the wrapper, we do not have to worry about telling Drupal
// what language we are using. The Entity API handles that for us.
  $ewrapper->title->set('Create Content Overivew');
// Setting the body is a bit different from other properties or fields
// because the body can have both its complete value and its
// summary
  $my_body_content = openberkeley_admin_node_add_page();
  $ewrapper->body->set(array('value' => $my_body_content));
  $my_date = new DateTime('August 29, 2014');
  $entity->field_my_date[LANGUAGE_NONE][0] = array(
    'value' => date_format($my_date, 'Y-m-d'),
    'timezone' => 'UTC',
    'timezone_db' => 'UTC',
  );
// Now just save the wrapper and the entity
// There is some suggestion that the 'true' argument is necessary to
// the entity save method to circumvent a bug in Entity API. If there is
// such a bug, it almost certainly will get fixed, so make sure to check.
  $ewrapper->save();
}