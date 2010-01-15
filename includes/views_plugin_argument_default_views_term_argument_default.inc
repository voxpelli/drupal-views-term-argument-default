<?php
// $Id$

/**
 * @file
 * Views extensions for argument defaults for the current node's terms
 */

class views_plugin_argument_default_views_term_argument_default extends views_plugin_argument_default {
  function construct() {
    parent::construct();
    $this->default_vocabulary = empty($this->definition['vocabulary']) ? FALSE : $this->definition['vocabulary'];
  }

  function get_argument() {
    $return = array();
    $nid    = intval(arg(1), 10);
    if (arg(0) == 'node' && $nid) {
      $terms  = views_term_argument_default_node_get_terms($nid);
      foreach ($terms as $term) {
        if (!$this->default_vocabulary || $term->vid == $this->default_vocabulary) {
          $return[] = $term->tid;
        }
      }
    }
    return implode('+', $return);
  }
}
