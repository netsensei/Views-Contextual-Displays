<?php
// $Id:$

/**
 * @file
 * Contains the base row style plugin.
 */

/**
 * The VCD row plugin. It extends the DS Object row plugin
 *
 * This plugin adds one extra option to the DS row plugin and allows for the use
 * of a contextual based build mode switching.
 *
 * @ingroup views_row_plugins
 */
class views_plugin_row_vcd extends views_plugin_ds_object_view {
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form(&$form, &$form_state);
    
    $views_base_table = $this->view->base_table;
    $build_mode_options = array();
    $build_modes = ds_get_build_modes();
    foreach ($build_modes as $module => $modes) {
      $function = $module .'_ds_api';
      $api_info = $function();
      // $api_info['views_base'] can either be a string or an array.
      if ((is_array($api_info['views_base']) && in_array($views_base_table, $api_info['views_base'])) || (is_string($api_info['views_base']) && $api_info['views_base'] == $views_base_table)) {
        foreach ($modes as $key => $title) {
          $build_mode_options[$key] = $title['title'];
        }
      }
    }

    // Select the contextual build mode.
    $form['context_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Contextual build modes'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    
    $contexts = context_enabled_contexts();
    $contexts_values = array();
    foreach ($contexts as $name => $context) {
      $reactions = array_keys($context->reactions);
      if (in_array('vcd_views_context_reaction', $reactions)) {
        $conditions = array_keys($context->conditions);
        $form['context_fieldset']['context_' . $name] = array(
          '#type' => 'select',
          '#title' => t('Set buildmode for %s', array('%s' => $name)),
          '#options' => $build_mode_options,
          '#description' => t('Condtions: %s, Reactions: %e', array('%s' => implode(', ', $conditions), '%e' => implode(' ,', $reactions))),
        );
      }
    }
	}
	
	function options_submit($form, &$form_state) {
    foreach ($form_state['values']['row_options']['context_fieldset'] as $context => $buildmode) {
      $form_state['values']['row_options'][$context] = $buildmode;
    }
  }
}
