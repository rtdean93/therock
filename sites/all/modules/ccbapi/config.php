<?php
  $config['url'] = 'therock.ccbchurch.com';
  $config['username'] = 'rgroupapi';
  $config['password'] = 'therock4him';
  $config['path'] = str_replace( dirname( realpath( $_SERVER['DOCUMENT_ROOT'] ) ), '',  dirname( realpath( __FILE__ ) ) );
  $config['media_path'] = $config['path'] . '/media';