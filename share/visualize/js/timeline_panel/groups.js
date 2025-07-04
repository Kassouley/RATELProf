const groupsList = {};

const createNestedGroup = (parentGroup, id, content, value, treeLevel) => {
  if (!parentGroup.nested_groups[id]) {
    parentGroup.nested_groups[id] = {
      group: {
        className: "lvl-"+treeLevel+"-group-class",
        style: "color:var(--text-color);font-size:12px;text-align:right;background-color:var(--lvl-"+treeLevel+"-group-color)",
        id,
        content,
        value,
        treeLevel,
      },
      nested_groups: {},
    };
  }
  return parentGroup.nested_groups[id];
};


function get_group_id(event, d) {
  const group = groupsList[d];
  const args = event.args;

  let nestedGroupKey, nestedGroupName;
  if (["RATELPROF_DOMAIN_KERNEL", "RATELPROF_DOMAIN_BARRIEROR", "RATELPROF_DOMAIN_BARRIERAND"].includes(d)) {
    const gpu_id = args.gpu_id;
    const q_id = args.queue_id;
    event._event_kind = d === "RATELPROF_DOMAIN_KERNEL" ? "KERNEL" : "BARRIER";

    nestedGroupKey  = `${d}_${gpu_id}`;
    nestedGroupName = `GPU ID. ${gpu_id}`;

    const nestedGroup = createNestedGroup(group, nestedGroupKey, nestedGroupName, gpu_id, 2);

    nestedGroupKey  = `${d}_${gpu_id}_${q_id}`;
    nestedGroupName = `Queue ID. ${q_id}`;

    createNestedGroup(nestedGroup, nestedGroupKey, nestedGroupName, q_id, 3);
    
    traceMap.set(`Dispatch_${event.id}`, {
        className:  'non-highlighted',
        start:      args.dispatch_time,
        type:       "point",
        group:      nestedGroupKey,
        _event_kind: "DISPATCH",
        cid: event.id,
        args: {
          dispatched_event: event.content,
          dispatch_time: args.dispatch_time,
        }
    });

  } else if (d === "RATELPROF_DOMAIN_COPY") {
    const eng_id = args.engine_id;
    event._event_kind = "COPY";

    nestedGroupKey   = `${d}_${eng_id}`;
    nestedGroupName  = `SDMA ID. ${(eng_id == -1) ? "Unknown" : eng_id}`;
    
    createNestedGroup(group, nestedGroupKey, nestedGroupName, eng_id, 3);

  } else {
    const tid = args.tid;
    event._event_kind = "CPU";
    
    nestedGroupKey     = `${d}_${tid}`;
    nestedGroupName    = `TID. ${tid}`;
    
    createNestedGroup(group, nestedGroupKey, nestedGroupName, tid, 3);
  }

  return nestedGroupKey
}

function concatGroups(groupsList) {
  const result = [];

  for (const obj of Object.values(groupsList)) {
    const nestedIds = Object.values(obj.nested_groups).map(({ group }) => group.id);
    if (nestedIds.length > 0) {
      obj.group.nestedGroups = nestedIds;
    }
    result.push(obj.group);
    result.push(...concatGroups(obj.nested_groups));
  }
  return result;
}

let g = 1, c = 1000;
for (const [id, d] of Object.entries(domain_table)) {
    groupsList[id] = {
        group: {
            className: "lvl-1-group-class",
            style: "color:var(--text-color);background-color:var(--lvl-1-group-color);font-size:13px;text-align:left;",
            treeLevel: 1,
            id,
            content: "ⓘ " + d.name,
            title: d.desc,
            showNested: d.isGPU,
            value: d.isGPU ? g++ : c++
        },
        nested_groups: {}
    }
}