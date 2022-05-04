states_needed = set("mt ut wa or id nv ca az".split())

radio_stations = {"kone": set("id nv ut".split()), "ktwo": set("wa id mt".split()), "kthree": set("or nw ca".split()),
                 "kfour": set("nv ut".split()), "kfive": set("ca az".split())}

final_set_radio_stations = set()

# best_radio_station = None
# states_covered = set()

while states_needed:
    best_radio_station = None
    states_covered = set()
    for radio_station, states_for_radio_station in radio_stations.items():
        covered = states_needed & states_for_radio_station
        if len(covered) > len(states_covered):
            best_radio_station = radio_station
            states_covered = covered
    final_set_radio_stations.add(best_radio_station)
    states_needed -= states_covered

print(final_set_radio_stations)