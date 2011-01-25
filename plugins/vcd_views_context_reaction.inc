<?php

class vcd_views_context_reaction extends context_reaction {
	
	// THIS HIDDEN FIELD IS APPARENTLY NEEDED:  USE FOR STORAGE FOR DEFAULT BUILD MODE?
  function options_form($context) {
    return array('debug' => array('#type' => 'value', '#value' => TRUE));
  }

  function options_form_submit($values) {
    return array('debug' => 1);
  }
	
  function execute(&$options, $build_mode) {
    $options['build_mode'] = $build_mode;
  }
}