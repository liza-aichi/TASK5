<?php
/**
 * @file
 * adress_book_views_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function adress_book_views_feature_default_rules_configuration() {
  $items = array();
  $items['rules_breadcrumps'] = entity_import('rules_config', '{ "rules_breadcrumps" : {
      "LABEL" : "add alias",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "path", "address_book" ],
      "ON" : { "contact_insert" : [], "contact_update" : [] },
      "DO" : [
        { "path_alias" : {
            "source" : "address-book\\/[contact:cid]\\/contact",
            "alias" : "address-book\\/[contact:title]-[contact:field-last-name]"
          }
        }
      ]
    }
  }');
  return $items;
}
