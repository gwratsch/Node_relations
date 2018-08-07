Node Relation module

Drupal 7 module.

This module will automaticly search possible links between nodes.
The title of other nodes will be used to search in the body of the to be saved 
node.
If the title is present in the body the node id and title will be added to the table 
'relation'.


Actions block:
    There are 2 block automaticly created to display the node relation and sub relation.
    Node relation : display all the node titles who are found in the body text of the
    displayed node.
    Node sub relation: display all the node titles where the title, of the displayed 
    node, was found in the body.

    Action: These blocks are 'Disabled'. Change the settings to display these blocks.
       Page: /admin/structure/block
       Open the block settings page and configure the blocks 'Node relation' and 'Node Sub relation'.


With the Rule action 'node relations save relations with other nodes.' the search
will start after saving the node.
    All the node titles will be collected en checked if the title is in the body 
    of the tobe saved node.

Check excisting nodes.
    If you already have many nodes created before installing this module you can 
    have these nodes automaticly checked.
    Solution 1 with a little number of nodes.
        Page : /admin/content
        Select alle the nodes en use the 'update  options'.
            Update options: select 'Publish selected content'
                This selection depends on the selected nodes. Look in the list and choose the moste suitable option.
                If you are not sure select only published nodes and use 'Publish selected content'.
            Button: update
            
    Solution 2 with bulk update
        You need the module 'views_bulk_operations'.
        After installing the module create a viewpage so you can search the info.
        In the FIELDS list you have to add 'Bulk operations' field.
            'Bulk operations' field settings:
               Bulk Operations settings:
                    select: 
                    - Dropdown selectbox with Submit button
                    - Enable "Select all items on all pages"
                    - Make the whole row clickable
               Selected bulk operations
                    Here you will select the types of actions you want to use in the viewpage.
                    I selected :
                    - Operations settings : Show avalable tokens
                                          Display values : All
                    - Publish content
        Security: make sure that not everybody can use this viewpage. The executed actions can not be undone.   
