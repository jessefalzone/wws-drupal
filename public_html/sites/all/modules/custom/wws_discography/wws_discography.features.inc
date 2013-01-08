<?php
/**
 * @file
 * wws_discography.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function wws_discography_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panels" && $api == "layouts") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function wws_discography_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function wws_discography_image_default_styles() {
  $styles = array();

  // Exported image style: medium_album.
  $styles['medium_album'] = array(
    'name' => 'medium_album',
    'effects' => array(
      1 => array(
        'label' => 'Desaturate',
        'help' => 'Desaturate converts an image to grayscale.',
        'effect callback' => 'image_desaturate_effect',
        'dimensions passthrough' => TRUE,
        'module' => 'image',
        'name' => 'image_desaturate',
        'data' => array(),
        'weight' => '-10',
      ),
      3 => array(
        'label' => 'Rotate',
        'help' => 'Rotating an image may cause the dimensions of an image to increase to fit the diagonal.',
        'effect callback' => 'image_rotate_effect',
        'dimensions callback' => 'image_rotate_dimensions',
        'form callback' => 'image_rotate_form',
        'summary theme' => 'image_rotate_summary',
        'module' => 'image',
        'name' => 'image_rotate',
        'data' => array(
          'degrees' => '60',
          'bgcolor' => '#FFFFFF',
          'random' => 1,
        ),
        'weight' => '-9',
      ),
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '200',
          'height' => '200',
        ),
        'weight' => '-8',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function wws_discography_node_info() {
  $items = array(
    'album' => array(
      'name' => t('album'),
      'base' => 'node_content',
      'description' => t('Music Album'),
      'has_title' => '1',
      'title_label' => t('Album Title'),
      'help' => '',
    ),
    'track' => array(
      'name' => t('Track'),
      'base' => 'node_content',
      'description' => t('This is a track.'),
      'has_title' => '1',
      'title_label' => t('Track Title'),
      'help' => '',
    ),
  );
  return $items;
}
