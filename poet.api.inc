<?php


function hook_poet_claim($attributes){
  $poet = new Poet();
  $poet->claim($attributes);
}
