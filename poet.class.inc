<?php

class Poet {

  public $pubKey;
  private $privKey;

  public __construct(){
      $this->pubKey = variable_get('poet_pubkey', false);
      $this->privKey = variable_get('poet_privkey', false);
      if(!$this->pubKey || !$this->privKey) {
        $this->errorLog('keys_missing');
      }
  }

  public function claim($attributes) {

  }

  private function errorLog($type) {
    switch($type) {
      case 'keys_missing':
        watchdog('poet', 'Private and/or public key missing. Go to /admin/config/poet/API to add your Po.et keys. ', array(), WATCHDOG_ERROR, $link = '/admin/config/poet/API');
      break;
    }
  }

}
