<?php

/**
 * @file
 * Contains Recipe entity add/edit form.
 */

/**
 * Add/edit form callback for contact entities.
 *
 * @param $form
 * @param $form_state
 * @param $contact
 * @param string $op
 */
function address_book_form($form, &$form_state, $contact, $op = 'edit')
{
    global $user;


    $form['title'] = array(
        '#type' => 'textfield',
        '#title' => t('First name'),
        '#required' => TRUE,
        '#default_value' => isset($contact->title) ? $contact->title : '',
    );

    $form['actions'] = array(
        '#type' => 'actions',
        'submit' => array(
            '#type' => 'submit',
            '#value' => t('Save'),
        ),


    );
    hide($form['field_user_id1']);

    field_attach_form('address_book', $contact, $form, $form_state);


    return $form;
}

/**
 * Submit callback for "contact_form".
 *
 * @param $form
 * @param $form_state
 */
function address_book_form_submit($form, &$form_state)
{
    global $user;
    $contact = entity_ui_form_submit_build_entity($form, $form_state);

    $contact->field_user_id1['und'] = array(0 => array('value' => $user->uid));

    $contact->save();
    drupal_set_message(
        t(
            'Contact @first_name @last_name was saved', array(
            '@first_name' => $form_state['values']['title'],
            '@last_name' => $form_state['values']['field_last_name1']['und'][0]['value']
        ))
    );


}