<?php

/**
 * Sections data store (array)
 *
 */
    
// Add path and title to $sections array

function add_path(&$sections, $path, $title = NULL) {

  // dpm($sections);
  // dpm($path);
  
  if($path != '') {
  
    if($title == NULL) {
    
      $title = $path;
    }

    // <front> handle that path or lowercase that path
    if($path == '<front>') {
        
      $path = '&lt;front&gt;';
      $title = 'Front';
      
    } else {
    
      $path = strtolower($path);
    }
    
    if(!isset($sections[$path])) {
    
      $sections[$path] = $title;
    }
  }
}

// Add Drupal menus to $sections array

function add_menu(&$sections, $menu) {

  // dpm($menu);

  foreach($menu as $key => $value) {
  
    $title = $menu[$key]['title'];
    $path = $menu[$key]['href']; 
    
    // convert 'node/123' paths to aliases
    $path_type = explode('/', $path);
    
    if($path_type[0] == 'node') {
    
      $path = drupal_lookup_path('alias', $path);    
    }
    
    add_path($sections, $path, $title);
  }
}

function sections_main_menu() {

  $menu = menu_main_menu();
  $sections = array();
    
  foreach($menu as $key => $value) {
  
    $sections[] = $menu[$key]['title'];
  }
  
  return $sections;
}



/**
 * Path matching logic
 *
 * URL paths in format: admin/structure/block/page/<alias> or ../<node/123>
 */

function alias_path() {

  return arg(4);
}

function node_path() {

  // cater for 'node/123' paths
  return arg(4) . '/' . arg(5);
}

function arg_matches_paths($paths) {

  foreach($paths as $key => $value) {
  
    $path = strtolower($value);
    

    if($path == arg(4) || $path == node_path()) {
    
      return true;
    }
  }
}

function match_path($path, $path2) {

  $path = strtolower($path);
  $path2 = strtolower($path2);
  
  if(!isset($sections[$path])) {
  
    $sections[$path] = $path;
    
  }
}