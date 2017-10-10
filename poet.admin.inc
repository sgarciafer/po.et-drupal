<?php


/**
 * Callback for the admin settings page of Po.et
 **/
function poet_settings_callback(){
  $form = array();

  $Poet = new Poet();

  $form['poet_url'] = array(
    '#type' => 'textfield',
    '#title' => t('The poet node url'),
    '#default_value' => variable_get('poet_url','https://alpha.po.et'),
    '#description' => t('ex: https://alpha.po.et'),
    '#size' => 60,
    '#maxlength' => 60,
    '#required' => TRUE,
  );

  $form['poet_pubkey'] = array(
    '#type' => 'textarea',
    '#title' => t('Public Key'),
    '#description' => t('This is Po.et public key used to sign your data.'),
    '#default_value' => $Poet->getPubKey(),
    '#disabled' => 'disabled',
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
