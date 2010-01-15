<?php
// $Id$

/**
 * @file
 * Views extensions for cities
 */

/**
 * Implementation of hook_views_plugins().
 */
function views_term_argument_default_views_plugins() {
  $base = array(
    'handler'    => 'views_plugin_argument_default_views_term_argument_default',
    'parent'     => 'fixed', // so that the parent class is included
    'path'       => drupal_get_path('module', 'views_term_argument_default') . '/includes',
  );

  $defaults = array(
    'views_term_argument_default' => array(
      'title'      => t("All terms on current node"),
    ) + $base,
  );

  //TODO: Instead of adding inf with argument defaults for each vocabulary - make it configurable through a form on the argument default itself?
  $vocabularies = taxonomy_get_vocabularies();
  foreach ($vocabularies as $vocabulary) {
    $defaults['views_term_argument_default_vocab_' . $vocabulary->vid] = array(
      'title'      => t("Terms from '@vocabulary' on current node", array('@vocabulary' => $vocabulary->name)),
      'vocabulary' => $vocabulary,
    ) + $base;
  }

  return array('argument default' => $defaults);
}