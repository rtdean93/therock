<?php

/**
 * Build a translation page for the given view.
 */
function i18nviews_translate_tab_page($view, $language = NULL) {
  module_load_include('inc', 'i18n_string', 'i18n_string.pages');
  $form_meta = array(
    '#page_title' => t('Translate view'),
    '#item_title_header' => t('View'),
    '#item_title_key' => array('views', $view->name, 'default', 'title'),
    '#item_title_default' => $view->human_name,
    '#edit' => 'admin/structure/views/view/' . $view->name . '/edit',
    '#translate' => 'admin/structure/views/view/' . $view->name . '/translate',
    '#items' => array(),
  );
  $view->init_display();
  foreach ($view->display as $display_id => $display) {
    $translatables = array();
    $display->handler->unpack_translatables($translatables);
    foreach ($translatables as $translatable) {
      $form_meta['#items'][] = array(
        '#title' => $display_id . ' ' . implode(':', $translatable['keys']),
        '#string_key' => array_merge(array('views', $view->name, $display_id), $translatable['keys']),
        '#default_value' => $translatable['value'],
      );
    }
  }
  return i18n_string_translate_page($form_meta, $language);
}

