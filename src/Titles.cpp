/*************************************************************************/
/*  Xania (M)ulti(U)ser(D)ungeon server source code                      */
/*  (C) 2021 Xania Development Team                                      */
/*  See merc.h and README for original copyrights                        */
/*************************************************************************/
#include "Titles.hpp"

const char *title_table[MAX_CLASS][MAX_LEVEL + 1][2] = {{{"Man", "Woman"},

                                                         {"Apprentice of Magic", "Apprentice of Magic"},
                                                         {"Apprentice of Magic", "Apprentice of Magic"},
                                                         {"Apprentice of Magic", "Apprentice of Magic"},
                                                         {"Spell Student", "Spell Student"},
                                                         {"Spell Student", "Spell Student"},

                                                         {"Spell Student", "Spell Student"},
                                                         {"Scholar of Magic", "Scholar of Magic"},
                                                         {"Scholar of Magic", "Scholar of Magic"},
                                                         {"Scholar of Magic", "Scholar of Magic"},
                                                         {"Delver in Spells", "Delveress in Spells"},

                                                         {"Delver in Spells", "Delveress in Spells"},
                                                         {"Delver in Spells", "Delveress in Spells"},
                                                         {"Medium of Magic", "Medium of Magic"},
                                                         {"Medium of Magic", "Medium of Magic"},
                                                         {"Medium of Magic", "Medium of Magic"},

                                                         {"Scribe of Magic", "Scribess of Magic"},
                                                         {"Scribe of Magic", "Scribess of Magic"},
                                                         {"Scribe of Magic", "Scribess of Magic"},
                                                         {"Seer", "Seeress"},
                                                         {"Seer", "Seeress"},

                                                         {"Seer", "Seeress"},
                                                         {"Sage", "Sage"},
                                                         {"Sage", "Sage"},
                                                         {"Sage", "Sage"},
                                                         {"Illusionist", "Illusionist"},

                                                         {"Illusionist", "Illusionist"},
                                                         {"Illusionist", "Illusionist"},
                                                         {"Abjurer", "Abjuress"},
                                                         {"Abjurer", "Abjuress"},
                                                         {"Abjurer", "Abjuress"},

                                                         {"Invoker", "Invoker"},
                                                         {"Invoker", "Invoker"},
                                                         {"Invoker", "Invoker"},
                                                         {"Enchanter", "Enchantress"},
                                                         {"Enchanter", "Enchantress"},

                                                         {"Enchanter", "Enchantress"},
                                                         {"Conjurer", "Conjuress"},
                                                         {"Conjurer", "Conjuress"},
                                                         {"Conjurer", "Conjuress"},
                                                         {"Magician", "Witch"},

                                                         {"Magician", "Witch"},
                                                         {"Magician", "Witch"},
                                                         {"Creator", "Creator"},
                                                         {"Creator", "Creator"},
                                                         {"Creator", "Creator"},

                                                         {"Savant", "Savant"},
                                                         {"Savant", "Savant"},
                                                         {"Savant", "Savant"},
                                                         {"Magus", "Craftess"},
                                                         {"Magus", "Craftess"},

                                                         {"Magus", "Craftess"},
                                                         {"Wizard", "Wizard"},
                                                         {"Wizard", "Wizard"},
                                                         {"Wizard", "Wizard"},
                                                         {"Warlock", "War Witch"},

                                                         {"Warlock", "War Witch"},
                                                         {"Warlock", "War Witch"},
                                                         {"Sorcerer", "Sorceress"},
                                                         {"Sorcerer", "Sorceress"},
                                                         {"Sorcerer", "Sorceress"},

                                                         {"Elder Sorcerer", "Elder Sorceress"},
                                                         {"Elder Sorcerer", "Elder Sorceress"},
                                                         {"Elder Sorcerer", "Elder Sorceress"},
                                                         {"Grand Sorcerer", "Grand Sorceress"},
                                                         {"Grand Sorcerer", "Grand Sorceress"},

                                                         {"Great Sorcerer", "Great Sorceress"},
                                                         {"Great Sorcerer", "Great Sorceress"},
                                                         {"Great Sorcerer", "Great Sorceress"},
                                                         {"Golem Maker", "Golem Maker"},
                                                         {"Golem Maker", "Golem Maker"},

                                                         {"Greater Golem Maker", "Greater Golem Maker"},
                                                         {"Greater Golem Maker", "Greater Golem Maker"},
                                                         {"Maker of Stones", "Maker of Stones"},
                                                         {"Maker of Stones", "Maker of Stones"},
                                                         {"Maker of Potions", "Maker of Potions"},

                                                         {"Maker of Potions", "Maker of Potions"},
                                                         {"Maker of Scrolls", "Maker of Scrolls"},
                                                         {"Maker of Scrolls", "Maker of Scrolls"},
                                                         {"Maker of Wands", "Maker of Wands"},
                                                         {"Maker of Wands", "Maker of Wands"},

                                                         {"Maker of Staves", "Maker of Staves"},
                                                         {"Maker of Staves", "Maker of Staves"},
                                                         {"Demon Summoner", "Demon Summoner"},
                                                         {"Demon Summoner", "Demon Summoner"},
                                                         {"Greater Demon Summoner", "Greater Demon Summoner"},

                                                         {"Greater Demon Summoner", "Greater Demon Summoner"},
                                                         {"Dragon Charmer", "Dragon Charmer"},
                                                         {"Dragon Charmer", "Dragon Charmer"},
                                                         {"Greater Dragon Charmer", "Greater Dragon Charmer"},
                                                         {"Master of all Magic", "Master of all Magic"},

                                                         {"Master Mage", "Master Mage"},
                                                         {"Avatar of Magic", "Avatar of Magic"},
                                                         {"Angel of Magic", "Angel of Magic"},
                                                         {"Demigod of Magic", "Demigoddess of Magic"},
                                                         {"Immortal of Magic", "Immortal of Magic"},

                                                         {"God of Magic", "Goddess of Magic"},
                                                         {"Deity of Magic", "Deity of Magic"},
                                                         {"Supremity of Magic", "Supremity of Magic"},
                                                         {"Creator", "Creator"},
                                                         {"Implementor", "Implementress"}},

                                                        {{"Man", "Woman"},

                                                         {"Believer", "Believer"},
                                                         {"Believer", "Believer"},
                                                         {"Believer", "Believer"},
                                                         {"Attendant", "Attendant"},
                                                         {"Attendant", "Attendant"},

                                                         {"Attendant", "Attendant"},
                                                         {"Acolyte", "Acolyte"},
                                                         {"Acolyte", "Acolyte"},
                                                         {"Acolyte", "Acolyte"},
                                                         {"Novice", "Novice"},

                                                         {"Novice", "Novice"},
                                                         {"Novice", "Novice"},
                                                         {"Missionary", "Missionary"},
                                                         {"Missionary", "Missionary"},
                                                         {"Missionary", "Missionary"},

                                                         {"Adept", "Adept"},
                                                         {"Adept", "Adept"},
                                                         {"Adept", "Adept"},
                                                         {"Deacon", "Deaconess"},
                                                         {"Deacon", "Deaconess"},

                                                         {"Deacon", "Deaconess"},
                                                         {"Vicar", "Vicaress"},
                                                         {"Vicar", "Vicaress"},
                                                         {"Vicar", "Vicaress"},
                                                         {"Priest", "Priestess"},

                                                         {"Priest", "Priestess"},
                                                         {"Priest", "Priestess"},
                                                         {"Priest", "Priestess"},
                                                         {"Minister", "Lady Minister"},
                                                         {"Minister", "Lady Minister"},

                                                         {"Minister", "Lady Minister"},
                                                         {"Canon", "Canon"},
                                                         {"Canon", "Canon"},
                                                         {"Canon", "Canon"},
                                                         {"Levite", "Levitess"},

                                                         {"Levite", "Levitess"},
                                                         {"Levite", "Levitess"},
                                                         {"Curate", "Curess"},
                                                         {"Curate", "Curess"},
                                                         {"Curate", "Curess"},

                                                         {"Monk", "Nun"},
                                                         {"Monk", "Nun"},
                                                         {"Monk", "Nun"},
                                                         {"Healer", "Healess"},
                                                         {"Healer", "Healess"},

                                                         {"Healer", "Healess"},
                                                         {"Chaplain", "Chaplain"},
                                                         {"Chaplain", "Chaplain"},
                                                         {"Chaplain", "Chaplain"},
                                                         {"Expositor", "Expositress"},

                                                         {"Expositor", "Expositress"},
                                                         {"Expositor", "Expositress"},
                                                         {"Bishop", "Bishop"},
                                                         {"Bishop", "Bishop"},
                                                         {"Bishop", "Bishop"},

                                                         {"Arch Bishop", "Arch Lady of the Church"},
                                                         {"Arch Bishop", "Arch Lady of the Church"},
                                                         {"Arch Bishop", "Arch Lady of the Church"},
                                                         {"Patriarch", "Matriarch"},
                                                         {"Patriarch", "Matriarch"},

                                                         {"Patriarch", "Matriarch"},
                                                         {"Elder Patriarch", "Elder Matriarch"},
                                                         {"Elder Patriarch", "Elder Matriarch"},
                                                         {"Elder Patriarch", "Elder Matriarch"},
                                                         {"Grand Patriarch", "Grand Matriarch"},

                                                         {"Grand Patriarch", "Grand Matriarch"},
                                                         {"Great Patriarch", "Great Matriarch"},
                                                         {"Great Patriarch", "Great Matriarch"},
                                                         {"Great Patriarch", "Great Matriarch"},
                                                         {"Demon Killer", "Demon Killer"},

                                                         {"Demon Killer", "Demon Killer"},
                                                         {"Demon Killer", "Demon Killer"},
                                                         {"Greater Demon Killer", "Greater Demon Killer"},
                                                         {"Greater Demon Killer", "Greater Demon Killer"},
                                                         {"Greater Demon Killer", "Greater Demon Killer"},

                                                         {"Cardinal of the Sea", "Cardinal of the Sea"},
                                                         {"Cardinal of the Sea", "Cardinal of the Sea"},
                                                         {"Cardinal of the Earth", "Cardinal of the Earth"},
                                                         {"Cardinal of the Earth", "Cardinal of the Earth"},
                                                         {"Cardinal of the Air", "Cardinal of the Air"},

                                                         {"Cardinal of the Air", "Cardinal of the Air"},
                                                         {"Cardinal of the Ether", "Cardinal of the Ether"},
                                                         {"Cardinal of the Ether", "Cardinal of the Ether"},
                                                         {"Cardinal of the Heavens", "Cardinal of the Heavens"},
                                                         {"Cardinal of the Heavens", "Cardinal of the Heavens"},

                                                         {"Avatar of an Immortal", "Avatar of an Immortal"},
                                                         {"Avatar of a Deity", "Avatar of a Deity"},
                                                         {"Avatar of a Supremity", "Avatar of a Supremity"},
                                                         {"Avatar of an Implementor", "Avatar of an Implementor"},
                                                         {"Master of all Divinity", "Mistress of all Divinity"},

                                                         {"Holy Hero", "Holy Heroine"},
                                                         {"Holy Avatar", "Holy Avatar"},
                                                         {"Angel", "Angel"},
                                                         {"Demigod", "Demigoddess"},
                                                         {"Immortal", "Immortal"},

                                                         {"God", "Goddess"},
                                                         {"Deity", "Deity"},
                                                         {"Supreme Master", "Supreme Mistress"},
                                                         {"Creator", "Creator"},
                                                         {"Implementor", "Implementress"}},

                                                        {{"Man", "Woman"},

                                                         {"Swordpupil", "Swordpupil"},
                                                         {"Swordpupil", "Swordpupil"},
                                                         {"Swordpupil", "Swordpupil"},
                                                         {"Recruit", "Recruit"},
                                                         {"Recruit", "Recruit"},

                                                         {"Recruit", "Recruit"},
                                                         {"Recruit", "Recruit"},
                                                         {"Sentry", "Sentress"},
                                                         {"Sentry", "Sentress"},
                                                         {"Sentry", "Sentress"},

                                                         {"Fighter", "Fighter"},
                                                         {"Fighter", "Fighter"},
                                                         {"Fighter", "Fighter"},
                                                         {"Soldier", "Soldier"},
                                                         {"Soldier", "Soldier"},

                                                         {"Soldier", "Soldier"},
                                                         {"Warrior", "Warrior"},
                                                         {"Warrior", "Warrior"},
                                                         {"Warrior", "Warrior"},
                                                         {"Veteran", "Veteran"},

                                                         {"Veteran", "Veteran"},
                                                         {"Veteran", "Veteran"},
                                                         {"Swordsman", "Swordswoman"},
                                                         {"Swordsman", "Swordswoman"},
                                                         {"Swordsman", "Swordswoman"},

                                                         {"Fencer", "Fenceress"},
                                                         {"Fencer", "Fenceress"},
                                                         {"Fencer", "Fenceress"},
                                                         {"Combatant", "Combatess"},
                                                         {"Combatant", "Combatess"},

                                                         {"Combatant", "Combatess"},
                                                         {"Hero", "Heroine"},
                                                         {"Hero", "Heroine"},
                                                         {"Hero", "Heroine"},
                                                         {"Myrmidon", "Myrmidon"},

                                                         {"Myrmidon", "Myrmidon"},
                                                         {"Swashbuckler", "Swashbuckleress"},
                                                         {"Swashbuckler", "Swashbuckleress"},
                                                         {"Swashbuckler", "Swashbuckleress"},
                                                         {"Mercenary", "Mercenaress"},

                                                         {"Mercenary", "Mercenaress"},
                                                         {"Mercenary", "Mercenaress"},
                                                         {"Swordmaster", "Swordmistress"},
                                                         {"Swordmaster", "Swordmistress"},
                                                         {"Swordmaster", "Swordmistress"},

                                                         {"Lieutenant", "Lieutenant"},
                                                         {"Lieutenant", "Lieutenant"},
                                                         {"Lieutenant", "Lieutenant"},
                                                         {"Champion", "Lady Champion"},
                                                         {"Champion", "Lady Champion"},

                                                         {"Champion", "Lady Champion"},
                                                         {"Dragoon", "Lady Dragoon"},
                                                         {"Dragoon", "Lady Dragoon"},
                                                         {"Dragoon", "Lady Dragoon"},
                                                         {"Cavalier", "Lady Cavalier"},

                                                         {"Cavalier", "Lady Cavalier"},
                                                         {"Cavalier", "Lady Cavalier"},
                                                         {"Knight", "Lady Knight"},
                                                         {"Knight", "Lady Knight"},
                                                         {"Knight", "Lady Knight"},

                                                         {"Grand Knight", "Grand Knight"},
                                                         {"Grand Knight", "Grand Knight"},
                                                         {"Grand Knight", "Grand Knight"},
                                                         {"Master Knight", "Master Knight"},
                                                         {"Master Knight", "Master Knight"},

                                                         {"Paladin", "Paladin"},
                                                         {"Paladin", "Paladin"},
                                                         {"Grand Paladin", "Grand Paladin"},
                                                         {"Grand Paladin", "Grand Paladin"},
                                                         {"Demon Slayer", "Demon Slayer"},

                                                         {"Demon Slayer", "Demon Slayer"},
                                                         {"Greater Demon Slayer", "Greater Demon Slayer"},
                                                         {"Greater Demon Slayer", "Greater Demon Slayer"},
                                                         {"Dragon Slayer", "Dragon Slayer"},
                                                         {"Dragon Slayer", "Dragon Slayer"},

                                                         {"Greater Dragon Slayer", "Greater Dragon Slayer"},
                                                         {"Greater Dragon Slayer", "Greater Dragon Slayer"},
                                                         {"Underlord", "Underlord"},
                                                         {"Underlord", "Underlord"},
                                                         {"Overlord", "Overlord"},

                                                         {"Baron of Thunder", "Baroness of Thunder"},
                                                         {"Baron of Thunder", "Baroness of Thunder"},
                                                         {"Baron of Storms", "Baroness of Storms"},
                                                         {"Baron of Storms", "Baroness of Storms"},
                                                         {"Baron of Lightning", "Baroness of Lightning"},

                                                         {"Baron of Tornadoes", "Baroness of Tornadoes"},
                                                         {"Baron of Hurricanes", "Baroness of Hurricanes"},
                                                         {"Baron of Meteors", "Baroness of Meteors"},
                                                         {"Baron of the Earth", "Baroness of the Earth"},
                                                         {"Master Warrior", "Master Warrior"},

                                                         {"Knight Hero", "Knight Heroine"},
                                                         {"Avatar of War", "Avatar of War"},
                                                         {"Angel of War", "Angel of War"},
                                                         {"Demigod of War", "Demigoddess of War"},
                                                         {"Immortal Warlord", "Immortal Warlord"},

                                                         {"God of War", "God of War"},
                                                         {"Deity of War", "Deity of War"},
                                                         {"Supreme Master of War", "Supreme Mistress of War"},
                                                         {"Creator", "Creator"},
                                                         {"Implementor", "Implementress"}},

                                                        {{"Man", "Woman"},

                                                         {"Axeman", "Axewoman"},
                                                         {"Axeman", "Axewoman"},
                                                         {"Axeman", "Axewoman"},
                                                         {"Rogue", "Rogue"},
                                                         {"Rogue", "Rogue"},

                                                         {"Rogue", "Rogue"},
                                                         {"Nomad", "Nomad "},
                                                         {"Nomad", "Nomad "},
                                                         {"Nomad", "Nomad "},
                                                         {"Strongman", "Strongwoman"},

                                                         {"Strongman", "Strongwoman"},
                                                         {"Strongman", "Strongwoman"},
                                                         {"Bold", "Bold"},
                                                         {"Bold", "Bold"},
                                                         {"Bold", "Bold"},

                                                         {"Renegade", "Renegade"},
                                                         {"Renegade", "Renegade"},
                                                         {"Renegade", "Renegade"},
                                                         {"Cut-throat", "Cut-throat"},
                                                         {"Cut-throat", "Cut-throat"},

                                                         {"Mighty", "Mighty"},
                                                         {"Mighty", "Mighty"},
                                                         {"Mighty", "Mighty"},
                                                         {"Warrior", "Warrior"},
                                                         {"Warrior", "Warrior"},

                                                         {"Warrior", "Warrior"},
                                                         {"Executioner", "Executioner"},
                                                         {"Executioner", "Executioner"},
                                                         {"Executioner", "Executioner"},
                                                         {"Weapons Crafter", "Weapons Crafter"},

                                                         {"Weapons Crafter", "Weapons Crafter"},
                                                         {"Weapons Crafter", "Weapons Crafter"},
                                                         {"Weapons Master", "Weapons Mistress"},
                                                         {"Weapons Master", "Weapons Mistress"},
                                                         {"Weapons Master", "Weapons Mistress"},

                                                         {"Highwayman", "Highwaywoman"},
                                                         {"Highwayman", "Highwaywoman"},
                                                         {"Highwayman", "Highwaywoman"},
                                                         {"Fearless", "Fearless"},
                                                         {"Fearless", "Fearless"},

                                                         {"Fearless", "Fearless"},
                                                         {"Barbarian", "Barbarian"},
                                                         {"Barbarian", "Barbarian"},
                                                         {"Barbarian", "Barbarian"},
                                                         {"Kinsman", "Kinswoman"},

                                                         {"Kinsman", "Kinswoman"},
                                                         {"Kinsman", "Kinswoman"},
                                                         {"Provider", "Provider"},
                                                         {"Provider", "Provider"},
                                                         {"Provider", "Provider"},

                                                         {"Judicier", "Judicier"},
                                                         {"Judicier", "Judicier"},
                                                         {"Judicier", "Judicier"},
                                                         {"Slayer", "Slayer"},
                                                         {"Slayer", "Slayer"},

                                                         {"Slayer", "Slayer"},
                                                         {"Giant Slayer", "Giant Slayer"},
                                                         {"Giant Slayer", "Giant Slayer"},
                                                         {"Daemon Slayer", "Daemon Slayer"},
                                                         {"Daemon Slayer", "Daemon Slayer"},

                                                         {"Wanderer of the Plains", "Wanderer of the Plains"},
                                                         {"Wanderer of the Plains", "Wanderer of the Plains"},
                                                         {"Wanderer of the Plains", "Wanderer of the Plains"},
                                                         {"Wanderer of the Plains", "Wanderer of the Plains"},

                                                         {"Baron of the Plains", "Baroness of the Plains"},
                                                         {"Baron of the Plains", "Baroness of the Plains"},
                                                         {"Baron of the Plains", "Baroness of the Plains"},
                                                         {"Lord of the Plains", "Lady of the Plains"},
                                                         {"Lord of the Plains", "Lady of the Plains"},

                                                         {"Blade Master", "Blade Mistress"},
                                                         {"Blade Master", "Blade Mistress"},

                                                         {"Infamous", "Infamous"},
                                                         {"Infamous", "Infamous"},

                                                         {"Infamous", "Infamous"},

                                                         {"Master of Vision", "Mistress of Vision"},
                                                         {"Master of Vision", "Mistress of Vision"},

                                                         {"Master of Lore", "Mistress of Lore"},
                                                         {"Master of Lore", "Mistress of Lore"},

                                                         {"Master of the Hunt", "Mistress of the Hunt"},
                                                         {"Master of the Hunt", "Mistress of the Hunt"},

                                                         {"Master of the Hunt", "Mistress of the Hunt"},
                                                         {"Guardian of an Immortal", "Guardian of an Immortal"},
                                                         {"Guardian of an Implementor", "Guardian of an Implementor"},
                                                         {"Guardian of an Implementor", "Guardian of an Implementor"},
                                                         {"Master of the Wild", "Mistress of the Wild"},

                                                         {"King of the Animals", "Queen of the Animals"},
                                                         {"Guardian of Justice", "Guardian of Justice"},
                                                         {"Protector of the Planet", "Protector of the Planet"},
                                                         {"Legend of the Realm", "Legend of the Realm"},
                                                         {"Barbarian King", "Barbarian Queen"},

                                                         {"Hero of Barbarity", "Heroine of Barbarity"},
                                                         {"Avatar of Death", "Avatar of Death"},
                                                         {"Angel of Death", "Angel of Death"},
                                                         {"Demigod", "Demigoddess"},
                                                         {"Immortal", "Immortal"},

                                                         {"God of Barbarity", "Goddess of Barbarity"},
                                                         {"Deity", "Deity"},
                                                         {"Supreme Master", "Supreme Mistress"},
                                                         {"Creator", "Creator"},
                                                         {"Implementor", "Implementress"}}};
