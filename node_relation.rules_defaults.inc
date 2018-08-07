<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * info: https://www.drupal.org/node/884584
 * Tip:
 * Create a rule with the rules UI.
 * make an export of that rule.
 * Add to node_relation_default_rules_configuration() the rows ($rule= ..) for the new rule. ans add then between $configs[.. and return $configs.
 * Use the expport to configure the new rule in the function.
 * Check in rules if it works.
 * 
 * The new rule will be visible after flush all caches.
 * 
 * When we need custom event, actions and conditions. then create them in node_relation.rules.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function node_relation_default_rules_configuration() {
  $rule = rules_reaction_rule();
  $rule->label = 'node relations save relations with other nodes.';
  $rule->active = TRUE;
  $rule->event('node_update')
       ->condition('node_is_of_type', array('data:select' => 'node:type', 'type'=>array('value' => 'article')))
       ->action('php_eval', array("code" => "\$nid = \$node->nid;\r\nnode_relation_build_relation(\$nid);" ));

  $configs['node_relation_saveRelation'] = $rule;
  return $configs;
}
