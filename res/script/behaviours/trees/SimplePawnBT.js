


// manualy

var SimplePawnBT = new b3.BehaviorTree();

SimplePawnBT.root = new b3.Sequence({children:[
    new b3.Priority({children: [
        new MyCustomNode(),
        new MyCustomNode()
    ]}),
]});


// json
/*var tree = new b3.BehaviorTree();

tree.load({
    'title'       : 'Behavior Tree title',
    'description' : 'My description',
    'root'        : 'node-id-1',
    'nodes'       : {
        'node-id-1' : {
            'name'        : 'Priority',
            'title'       : 'Root Node',
            'description' : 'Description',
            'children'    : ['node-id-2', 'node-id-3'],
        },
        ...
}
})*/



