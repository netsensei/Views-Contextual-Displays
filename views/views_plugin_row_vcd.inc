<?php
// $Id: views_plugin_row_fields.inc,v 1.2.2.1 2010/03/11 00:06:18 merlinofchaos Exp $
/**
 * @file
 * Contains the base row style plugin.
 */

/**
 * The basic 'fields' row plugin
 *
 * This displays fields one after another, giving options for inline
 * or not.
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

    // Default build mode.
    $form['context_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Contextual build modes'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );

    $form['context_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Contextual build modes'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
	}
}
