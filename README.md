# Poet bridge for Drupal 7

Module under development.
A Poet class will centralize the actions to perform.
A set of hooks are planned to integrate Poet module functionnalities on custom modules.
Also a submission during the save/update of a node for the nodes that have been set as "Poet" on their configuration will be done through this module.
Rules and actions are also planned.

Install
=======
This module requires the GMP PHP Math library.
To install it:

apt-get install php-gmp

Or for PHP5
apt-get install php5-gmp

Check the php.ini has
extension=php_gmp.so

Then install the module as any other Drupal module.

Configuration
=============
Register at po.et and paste the private and public keuys on the administration page of Poet module.
/admin/config/poet/API

For more details about this module contact: info@cubeinspire.com
