<?php
/**
 * @file
 * adress_book_views_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function adress_book_views_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'address_book';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'contact';
  $view->human_name = 'Address book';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Address book';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'cid' => 'cid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'cid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Bulk operations: Contact */
  $handler->display->display_options['fields']['views_bulk_operations_1']['id'] = 'views_bulk_operations_1';
  $handler->display->display_options['fields']['views_bulk_operations_1']['table'] = 'contact';
  $handler->display->display_options['fields']['views_bulk_operations_1']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Change category',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'contact::field_category_' => 'contact::field_category_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Contact: Photo */
  $handler->display->display_options['fields']['field_photo']['id'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo']['settings'] = array(
    'image_style' => 'contact_preview_img',
    'image_link' => 'content',
  );
  /* Field: Contact: Contact ID */
  $handler->display->display_options['fields']['cid_1']['id'] = 'cid_1';
  $handler->display->display_options['fields']['cid_1']['table'] = 'contact';
  $handler->display->display_options['fields']['cid_1']['field'] = 'cid';
  $handler->display->display_options['fields']['cid_1']['exclude'] = TRUE;
  /* Field: Contact: Last name */
  $handler->display->display_options['fields']['field_last_name_1']['id'] = 'field_last_name_1';
  $handler->display->display_options['fields']['field_last_name_1']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name_1']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name_1']['exclude'] = TRUE;
  /* Field: Contact: Label */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'contact';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Name:';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[title_1]  [field_last_name_1] ';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = 'address-book/[cid_1]/contact';
  /* Field: Contact: Category: */
  $handler->display->display_options['fields']['field_category_']['id'] = 'field_category_';
  $handler->display->display_options['fields']['field_category_']['table'] = 'field_data_field_category_';
  $handler->display->display_options['fields']['field_category_']['field'] = 'field_category_';
  $handler->display->display_options['fields']['field_category_']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Contact: Email: */
  $handler->display->display_options['fields']['field_email_']['id'] = 'field_email_';
  $handler->display->display_options['fields']['field_email_']['table'] = 'field_data_field_email_';
  $handler->display->display_options['fields']['field_email_']['field'] = 'field_email_';
  /* Field: Contact: Birthday */
  $handler->display->display_options['fields']['field_birthday']['id'] = 'field_birthday';
  $handler->display->display_options['fields']['field_birthday']['table'] = 'field_data_field_birthday';
  $handler->display->display_options['fields']['field_birthday']['field'] = 'field_birthday';
  $handler->display->display_options['fields']['field_birthday']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'address-book/manage/[cid_1] ';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Delete';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'address-book/manage/[cid_1]/delete?destination=address-book';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Contact: user_id */
  $handler->display->display_options['fields']['field_user_id']['id'] = 'field_user_id';
  $handler->display->display_options['fields']['field_user_id']['table'] = 'field_data_field_user_id';
  $handler->display->display_options['fields']['field_user_id']['field'] = 'field_user_id';
  $handler->display->display_options['fields']['field_user_id']['exclude'] = TRUE;
  /* Contextual filter: Contact: user_id (field_user_id) */
  $handler->display->display_options['arguments']['field_user_id_value']['id'] = 'field_user_id_value';
  $handler->display->display_options['arguments']['field_user_id_value']['table'] = 'field_data_field_user_id';
  $handler->display->display_options['arguments']['field_user_id_value']['field'] = 'field_user_id_value';
  $handler->display->display_options['arguments']['field_user_id_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_user_id_value']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_user_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_id_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_user_id_value']['limit'] = '0';
  /* Filter criterion: Contact: Category: (field_category_) */
  $handler->display->display_options['filters']['field_category__tid']['id'] = 'field_category__tid';
  $handler->display->display_options['filters']['field_category__tid']['table'] = 'field_data_field_category_';
  $handler->display->display_options['filters']['field_category__tid']['field'] = 'field_category__tid';
  $handler->display->display_options['filters']['field_category__tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_category__tid']['expose']['operator_id'] = 'field_category__tid_op';
  $handler->display->display_options['filters']['field_category__tid']['expose']['label'] = 'Category: ';
  $handler->display->display_options['filters']['field_category__tid']['expose']['operator'] = 'field_category__tid_op';
  $handler->display->display_options['filters']['field_category__tid']['expose']['identifier'] = 'field_category__tid';
  $handler->display->display_options['filters']['field_category__tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_category__tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_category__tid']['vocabulary'] = 'category';
  $handler->display->display_options['filters']['field_category__tid']['hierarchy'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'address-book';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Address Book';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'List';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['address_book'] = $view;

  $view = new view();
  $view->name = 'contact';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'contact';
  $view->human_name = 'Contact';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '[title] [field_last_name] ';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'cid' => 'cid',
    'field_category_' => 'field_category_',
    'field_email_' => 'field_email_',
    'field_phone' => 'field_phone',
    'field_birthday' => 'field_birthday',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Contact: Contact ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'contact';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['exclude'] = TRUE;
  /* Field: Contact: Photo */
  $handler->display->display_options['fields']['field_photo']['id'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['table'] = 'field_data_field_photo';
  $handler->display->display_options['fields']['field_photo']['field'] = 'field_photo';
  $handler->display->display_options['fields']['field_photo']['label'] = '';
  $handler->display->display_options['fields']['field_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo']['settings'] = array(
    'image_style' => 'contact_img',
    'image_link' => '',
  );
  /* Field: Contact: Label */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'contact';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Contact: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Contact: Category: */
  $handler->display->display_options['fields']['field_category_']['id'] = 'field_category_';
  $handler->display->display_options['fields']['field_category_']['table'] = 'field_data_field_category_';
  $handler->display->display_options['fields']['field_category_']['field'] = 'field_category_';
  $handler->display->display_options['fields']['field_category_']['label'] = 'Category';
  $handler->display->display_options['fields']['field_category_']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_category_']['element_wrapper_type'] = 'h4';
  /* Field: Contact: Email: */
  $handler->display->display_options['fields']['field_email_']['id'] = 'field_email_';
  $handler->display->display_options['fields']['field_email_']['table'] = 'field_data_field_email_';
  $handler->display->display_options['fields']['field_email_']['field'] = 'field_email_';
  $handler->display->display_options['fields']['field_email_']['label'] = 'Email';
  $handler->display->display_options['fields']['field_email_']['alter']['path'] = '[field_email_] ';
  $handler->display->display_options['fields']['field_email_']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_email_']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_email_']['element_wrapper_type'] = 'h4';
  /* Field: Contact: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_phone']['element_wrapper_type'] = 'h4';
  /* Field: Contact: Birthday */
  $handler->display->display_options['fields']['field_birthday']['id'] = 'field_birthday';
  $handler->display->display_options['fields']['field_birthday']['table'] = 'field_data_field_birthday';
  $handler->display->display_options['fields']['field_birthday']['field'] = 'field_birthday';
  $handler->display->display_options['fields']['field_birthday']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_birthday']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['field_birthday']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Contact: Notes */
  $handler->display->display_options['fields']['field_notes']['id'] = 'field_notes';
  $handler->display->display_options['fields']['field_notes']['table'] = 'field_data_field_notes';
  $handler->display->display_options['fields']['field_notes']['field'] = 'field_notes';
  $handler->display->display_options['fields']['field_notes']['label'] = '';
  $handler->display->display_options['fields']['field_notes']['element_label_colon'] = FALSE;
  /* Contextual filter: Contact: Contact ID */
  $handler->display->display_options['arguments']['cid']['id'] = 'cid';
  $handler->display->display_options['arguments']['cid']['table'] = 'contact';
  $handler->display->display_options['arguments']['cid']['field'] = 'cid';
  $handler->display->display_options['arguments']['cid']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['cid']['breadcrumb'] = 'Contact';
  $handler->display->display_options['arguments']['cid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['cid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['cid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['cid']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'address-book/%/contact';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['contact'] = $view;

  return $export;
}
