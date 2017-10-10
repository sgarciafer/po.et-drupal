<?php

use BitcoinPHP\BitcoinECDSA\BitcoinECDSA;
require_once("lib/vendor/bitcoin-php/bitcoin-ecdsa/src/BitcoinPHP/BitcoinECDSA/BitcoinECDSA.php");

class Poet {

  public $pubKey;
  private $privKey;
  private $BitcoinECDSA;

  // Check the priv/pub keys, if already exist, or automatically generates them.
  public function __construct(){

      $this->BitcoinECDSA = new BitcoinECDSA();

      $this->privKey = variable_get('poet_privkey', false);
      if( !$this->privKey ) $this->generatePrivKey();
      else $this->BitcoinECDSA->setPrivateKey($this->privKey);

      $this->generatePubKey();

      if(!$this->pubKey OR !$this->privKey) {
        $this->errorLog('keys_missing');
      }
  }

  public function claim($attributes) {

  }

  public function getPubKey() {
    return $this->BitcoinECDSA->getPubKey();
  }

  private function generatePubKey() {
    $this->pubKey = false;
    if($this->privKey) {
      $this->pubKey = $this->BitcoinECDSA->getPubKey();
    }
  }

  private function generatePrivKey() {
    if(!$this->privKey) {
      // A truely random nonce should be implemented on later updates. Maybe processing mouse movement through a configuration step.
      $this->privKey = $this->BitcoinECDSA->generateRandomPrivateKey(mt_rand(99999, mt_getrandmax()));
      $this->savePrivKey();
    }
  }

  private function savePrivKey() {
    if( !variable_get('poet_privkey', false) ) variable_set('poet_privkey', $this->BitcoinECDSA->getPrivateKey());
  }

  private function errorLog($type) {
    switch($type) {
      case 'keys_missing':
        watchdog('poet', 'There private key is wrong or missing. Go to /admin/config/poet/API to add your Po.et keys. ', array(), WATCHDOG_ERROR, $link = '/admin/config/poet/API');
      break;
    }
  }

}
