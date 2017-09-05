<?php


/**
 * Callback for the admin settings page of Po.et
 **/
function poet_settings_callback(){
  $form = array();

  $form['poet_pubkey'] = array(
    '#type' => 'textfield',
    '#title' => t('Public Key'),
    '#default_value' => variable_get('poet_pubkey',''),
    '#size' => 128,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['poet_privkey'] = array(
    '#type' => 'textfield',
    '#title' => t('Private Key'),
    '#description' => t('This is Po.et private key used to sign your data. Keep it secret.'),
    '#default_value' => variable_get('poet_privkey',''),
    '#size' => 128,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
