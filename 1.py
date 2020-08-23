from netzob.all import *
#Import messages from a PCAP file.
messages_session1 = PCAPImporter.readFile("./qq_login_password2.pcap",importLayer=3).values()
messages_session2 = PCAPImporter.readFile("./qq_login_password3.pcap",importLayer=3).values()
messages = messages_session1 + messages_session2
for message in messages:
    print(message)
#Regroup messages in a symbol and do a format partitionment with a delimiter
symbol = Symbol(messages=messages)
Format.splitDelimiter(symbol, ASCII(";"))
print("[+] Symbol structure:")
print(symbol._str_debug())
print("[+] Partitionned messages:")
print(symbol)
#Cluster according to a key field
symbols = Format.clusterByKeyField(symbol, symbol.fields[0])
print("[+] Number of symbols after clustering: {0}".format(len(symbols)))
print("[+] Symbol list:")
for keyFieldName, s in symbols.items():
    print(" * {0}".format(keyFieldName))
#Apply a format partitionment with a sequence alignment on the third field of each symbol
# for symbol in symbols.values():
# Format.splitAligned(symbol.fields[2], doInternalSlick=True)
# print("[+] Partitionned messages:")
# print(symbol)
#Find field relations in each symbol
for symbol in symbols.values():
    rels = RelationFinder.findOnSymbol(symbol)
    print("[+] Relations found: ")
    for rel in rels:
        print(" " + rel["relation_type"] + ", between '" + rel["x_attribute"] + "' of:")
        print(" " + str('-'.join([f.name for f in rel["x_fields"]])))
        p = [v.getValues()[:] for v in rel["x_fields"]]
        print(" " + str(p))
        print(" " + "and '" + rel["y_attribute"] + "' of:")
        print(" " + str('-'.join([f.name for f in rel["y_fields"]])))
        p = [v.getValues()[:] for v in rel["y_fields"]]
        print(" " + str(p))
#Generate a chained states automaton
session = Session(messages_session1)
abstractSession = session.abstract(list(symbols.values()))
automata = Automata.generateChainedStatesAutomata(abstractSession, list(symbo
ls.values()))
dotcode = automata.generateDotCode()
print(dotcode)