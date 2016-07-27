


// manualy

var SimplePawnBT = new b3.BehaviorTree();

SimplePawnBT.root = new b3.Sequence({children:[
    new b3.Priority({children: [
        new Wander(),
        new Chase()
    ]}),
]});






