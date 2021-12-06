#pragma once

#include "AFFECT_DATA.hpp"
#include "AffectFlag.hpp"
#include "AffectList.hpp"
#include "ArmourClass.hpp"
#include "CharActFlag.hpp"
#include "CharExtraFlag.hpp"
#include "CharVersion.hpp"
#include "CommFlag.hpp"
#include "Constants.hpp"
#include "Descriptor.hpp"
#include "Flag.hpp"
#include "Materials.hpp"
#include "MobIndexData.hpp"
#include "OffensiveFlag.hpp"
#include "PcData.hpp"
#include "PlayerActFlag.hpp"
#include "Position.hpp"
#include "Sex.hpp"
#include "Stats.hpp"
#include "Types.hpp"
#include "mob_prog.hpp"

#include <array>
#include <fmt/core.h>
#include <magic_enum.hpp>
#include <memory>
#include <string_view>

enum class ArmourClass;
enum class BodySize;
class Note;
class Sex;
struct MobIndexData;
struct Object;
struct Room;
struct PcCustomization;
struct MobProgAct;

struct LastLoginInfo {
    std::string login_from;
    std::string login_at;
};

/*
 * One character (PC or NPC).
 */
struct Char {
    Char *master{};
    Char *leader{};
    Char *fighting{};
    Char *reply{};
    Char *pet{};
    Char *riding{};
    Char *ridden_by{};
    SpecialFunc spec_fun{};
    MobIndexData *mobIndex{};
    Descriptor *desc{};
    AffectList affected;
    std::unique_ptr<Note> pnote;
    GenericList<Object *> carrying;
    Room *in_room{};
    Room *was_in_room{};
    std::unique_ptr<PcData> pcdata;
    std::string name;

    CharVersion version{};
    std::string short_descr;
    std::string long_descr;
    std::string description;
    std::string sentient_victim;
    Sex sex;
    sh_int class_num{};
    sh_int race{};
    sh_int level{};
    sh_int trust{};
    Seconds played{};
    int lines{PAGELEN}; /* for the pager */
    Time logon{};
    Time last_note{Time::min()};
    sh_int timer{};
    sh_int wait{};
    sh_int hit{20};
    sh_int max_hit{20};
    sh_int mana{100};
    sh_int max_mana{100};
    sh_int move{100};
    sh_int max_move{100};
    long gold{};
    long exp{};
    unsigned long act{};
    unsigned long comm{}; /* RT added to pad the vector */
    unsigned long imm_flags{};
    unsigned long res_flags{};
    unsigned long vuln_flags{};
    sh_int invis_level{};
    unsigned int affected_by{};
    Position position{};
    sh_int practice{};
    sh_int train{};
    sh_int carry_weight{};
    sh_int carry_number{};
    sh_int saving_throw{};
    sh_int alignment{};
    sh_int hitroll{};
    sh_int damroll{};
    std::array<sh_int, magic_enum::enum_count<ArmourClass>()> armor{};
    sh_int wimpy{};
    /* stats */
    Stats perm_stat;
    Stats mod_stat;
    /* parts stuff */
    unsigned long morphology{};
    unsigned long parts{};
    BodySize body_size{};
    Material::Type material{}; // TODO is this used in any meaningful way?
    /* mobile stuff */
    unsigned long off_flags{};
    Dice damage; // This is non-wielding damage, and does not include the damroll bonus.
    sh_int attack_type{}; // attack_table index.
    Position start_pos{};
    Position default_pos{};
    unsigned long extra_flags[(magic_enum::enum_count<CharExtraFlag>() / 32) + 1]{};
    std::vector<MobProgAct> mpact{};

    Char();
    ~Char();
    Char(const Char &) = delete;
    Char &operator=(const Char &) = delete;
    Char(Char &&) = delete;
    Char &operator=(Char &&) = delete;

    [[nodiscard]] Seconds total_played() const;

    // True if char can see victim.
    [[nodiscard]] bool can_see(const Char &victim) const;
    // True if char can see object.
    [[nodiscard]] bool can_see(const Object &object) const;
    // True if char can see a room.
    [[nodiscard]] bool can_see(const Room &room) const;

    [[nodiscard]] bool is_npc() const;
    [[nodiscard]] bool is_pc() const { return !is_npc(); }
    [[nodiscard]] bool is_warrior() const;
    [[nodiscard]] bool is_thief() const;
    [[nodiscard]] bool is_shopkeeper() const;

    // is_aff_() methods return true if the Char is affected by the relevant spell affect bit.
    // See: has_affect_bit() and is_affected_by().
    [[nodiscard]] bool is_aff_berserk() const;
    [[nodiscard]] bool is_aff_blind() const;
    [[nodiscard]] bool is_aff_calm() const;
    [[nodiscard]] bool is_aff_charm() const;
    [[nodiscard]] bool is_aff_curse() const;
    [[nodiscard]] bool is_aff_detect_evil() const;
    [[nodiscard]] bool is_aff_detect_hidden() const;
    [[nodiscard]] bool is_aff_detect_invis() const;
    [[nodiscard]] bool is_aff_detect_magic() const;
    [[nodiscard]] bool is_aff_faerie_fire() const;
    [[nodiscard]] bool is_aff_fly() const;
    [[nodiscard]] bool is_aff_haste() const;
    [[nodiscard]] bool is_aff_hide() const;
    [[nodiscard]] bool is_aff_infrared() const;
    [[nodiscard]] bool is_aff_invisible() const;
    [[nodiscard]] bool is_aff_lethargy() const;
    [[nodiscard]] bool is_aff_octarine_fire() const;
    [[nodiscard]] bool is_aff_plague() const;
    [[nodiscard]] bool is_aff_pass_door() const;
    [[nodiscard]] bool is_aff_poison() const;
    [[nodiscard]] bool is_aff_protection_evil() const;
    [[nodiscard]] bool is_aff_protection_good() const;
    [[nodiscard]] bool is_aff_regeneration() const;
    [[nodiscard]] bool is_aff_sanctuary() const;
    [[nodiscard]] bool is_aff_sneak() const;
    [[nodiscard]] bool is_aff_sleep() const;
    [[nodiscard]] bool is_aff_talon() const;

    // Some positional convenience methods in order of most to least vulnerable.
    [[nodiscard]] bool is_pos_dead() const;
    // Dead,  mortally wounded or incapacitated.
    [[nodiscard]] bool is_pos_dying() const;
    // Dead,  mortally wounded, incapacitated or stunned.
    [[nodiscard]] bool is_pos_stunned_or_dying() const;
    [[nodiscard]] bool is_pos_sleeping() const;
    [[nodiscard]] bool is_pos_relaxing() const;
    // True if the Char is in any state higher than Sleeping (note that this is _not_ the same as !is_sleeping())
    [[nodiscard]] bool is_pos_awake() const;
    [[nodiscard]] bool is_pos_fighting() const;
    // In any state other than standing ready for action.
    [[nodiscard]] bool is_pos_preoccupied() const;
    // Standing ready for action.
    [[nodiscard]] bool is_pos_standing() const;

    // Special states for Gods.
    [[nodiscard]] bool has_holylight() const;
    // Is the player wizinvis/prowl at all, and are they invisible to a particular character?
    [[nodiscard]] bool is_wizinvis() const;
    [[nodiscard]] bool is_wizinvis_to(const Char &victim) const;
    [[nodiscard]] bool is_prowlinvis() const;
    [[nodiscard]] bool is_prowlinvis_to(const Char &victim) const;

    // Returns whether this is a PC with brief set.
    [[nodiscard]] bool is_comm_brief() const;
    // Returns whether this is a PC with autoexits
    [[nodiscard]] bool should_autoexit() const;

    // Retrieve a character's trusted level for permission checking.
    [[nodiscard]] int get_trust() const;

    // Returns the PC character controlling this character,or nullptr if not controlled by a pc.
    // That is:
    // * For a player: return this
    // * For an NPC controlled by a switched IMM, return that IMM
    // * For a normal NPC, return null.
    [[nodiscard]] const Char *player() const { return desc ? desc->person() : nullptr; }
    [[nodiscard]] Char *player() { return desc ? desc->person() : nullptr; }
    [[nodiscard]] bool is_switched() const noexcept { return is_npc() && desc; }

    [[nodiscard]] bool is_immortal() const;
    [[nodiscard]] bool is_mortal() const { return !is_immortal(); }
    // True for max level mortals and for all immortals.
    [[nodiscard]] bool is_hero() const;

    // Return a character's skill at the given skill number
    [[nodiscard]] int get_skill(int skill_number) const;

    // Get current and maximum stats.
    [[nodiscard]] sh_int curr_stat(Stat stat) const;
    [[nodiscard]] sh_int max_stat(Stat stat) const;

    // Get the current armour class, taking into account Char position and dexterity.
    [[nodiscard]] sh_int get_armour_class(const ArmourClass ac_slot) const;

    // Return true if a char is affected by a spell based on its skill number (not its affect bit!)
    [[nodiscard]] bool is_affected_by(int skill_number) const;
    // Return true if a char is affected by a spell affect bit (not its skill number!)
    [[nodiscard]] bool has_affect_bit(int affect_bit) const;

    // Return true if the Room the Char is currently in is not flagged as indoor.
    [[nodiscard]] bool is_outside() const;
    // Return true if the Room the Char is currently in is flagged as indoor.
    [[nodiscard]] bool is_inside() const;

    // Return a pointer to the character's overall clan if they have one.
    [[nodiscard]] const Clan *clan() const;
    // Return a pointer to the character's individual clan membership info, if they have one.
    [[nodiscard]] PcClan *pc_clan();
    [[nodiscard]] const PcClan *pc_clan() const;

    // Send text to this character's user (if they have one).
    void send_to(std::string_view txt) const;
    template <typename... Args>
    void send_to(std::string_view txt, Args &&... args) const {
        return send_to(fmt::format(txt, std::forward<Args>(args)...));
    }
    // Send a line to this character's user (if they have one).
    void send_line(std::string_view txt) const { return send_to("{}\n\r", txt); }
    template <typename... Args>
    void send_line(std::string_view txt, Args &&... args) const {
        return send_to(fmt::format(txt, std::forward<Args>(args)...) + "\n\r");
    }

    // Page text to this character's user (if they have one).
    void page_to(std::string_view txt) const;

    // Set the Char's wait state to npulse if it is higher than the Char's current wait state.
    void wait_state(const sh_int npulse);

    // Sets a PC's title.
    void set_title(std::string title);

    // Gets an item in a character's inventory. Returns nullptr if not found. Supports numbered argument.
    [[nodiscard]] Object *find_in_inventory(std::string_view argument) const;

    // Gets an item a character is wearing. Returns nullptr if not found. Supports numbered argument.
    [[nodiscard]] Object *find_worn(std::string_view argument) const;

    // Return the name used to describe the char in short text.
    [[nodiscard]] std::string_view short_name() const noexcept {
        // TODO the cast to string_view is only needed while name isn't a std::string. remove soon!
        return is_pc() ? name : std::string_view(short_descr);
    }

    // Alignment.
    [[nodiscard]] bool is_good() const noexcept { return alignment >= 350; }
    [[nodiscard]] bool is_evil() const noexcept { return alignment <= -350; }
    [[nodiscard]] bool is_neutral() const noexcept { return !is_good() && !is_evil(); }

    // Crime.
    [[nodiscard]] bool is_player_killer() const noexcept;
    [[nodiscard]] bool is_player_thief() const noexcept;

    // Yell something. It's assumed all checks (e.g. message is not empty, victim has rights to yell) have been made
    void yell(std::string_view exclamation) const;
    // Say something.
    void say(std::string_view message);

    [[nodiscard]] static int num_active() { return num_active_; }

    // Extra bits.
    [[nodiscard]] bool is_set_extra(const CharExtraFlag flag) const noexcept;
    void set_extra(const CharExtraFlag flag) noexcept;
    void remove_extra(const CharExtraFlag flag) noexcept;
    [[nodiscard]] bool toggle_extra(const CharExtraFlag flag) noexcept;

    [[nodiscard]] int get_damroll() const noexcept;
    [[nodiscard]] int get_hitroll() const noexcept;

    void set_not_afk();
    void set_afk(std::string_view afk_message);

    [[nodiscard]] bool has_boat() const noexcept;
    [[nodiscard]] bool carrying_object_vnum(int vnum) const noexcept;

    [[nodiscard]] const Char &group_leader() const noexcept { return leader ? *leader : *this; }
    [[nodiscard]] Char &group_leader() noexcept { return leader ? *leader : *this; }
    [[nodiscard]] size_t num_group_members_in_room() const noexcept;

    void try_give_item_to(Object *object, Char *to_char);

    // Apply a delta to the Char's inebriation/hunger/thirst and return an optional
    // message to send to the player. Has no effect on NPCs.
    std::optional<std::string_view> delta_inebriation(const sh_int delta) noexcept;
    std::optional<std::string_view> delta_hunger(const sh_int delta) noexcept;
    std::optional<std::string_view> delta_thirst(const sh_int delta) noexcept;
    // Print the nutrition scores in words.
    [[nodiscard]] std::optional<std::string> describe_nutrition() const;
    // Print the nutrition scores numerically.
    [[nodiscard]] std::optional<std::string> report_nutrition() const;
    [[nodiscard]] bool is_inebriated() const noexcept;
    // Hungry means they may have some appetite but they may not be starving, and are not satisified.
    [[nodiscard]] bool is_hungry() const noexcept;
    // Starving is worse than hungry - a starving Char regenerates slower.
    [[nodiscard]] bool is_starving() const noexcept;
    // Thirsty means they may have some thirst but they may not be parched, and are not satisified.
    [[nodiscard]] bool is_thirsty() const noexcept;
    // Parched is worse than thirsty - a parched Char regenerates slower.
    [[nodiscard]] bool is_parched() const noexcept;

    // Return a string view describing the given character to this character, taking into account whether we can see the
    // other character.
    [[nodiscard]] std::string_view describe(const Char &to_describe) const noexcept;

    // Returns a string describing the CharExtraFlag bits the character has enabled.
    [[nodiscard]] std::string format_extra_flags() const noexcept;

    // Returns the CharExtraFlag bits in ASCII binary form, for saving to the pfile.
    [[nodiscard]] std::string serialize_extra_flags() const noexcept;

    inline static constexpr std::array<Flag, 30> AllAffectFlags = {{
        // clang-format off
        {to_int(AffectFlag::Blind), 0, "blind"},
        {to_int(AffectFlag::Invisible), 0, "invisible"},
        {to_int(AffectFlag::DetectEvil), 0, "detect_evil"},
        {to_int(AffectFlag::DetectInvis), 0, "detect_invis"},
        {to_int(AffectFlag::DetectMagic), 0, "detect_magic"},
        {to_int(AffectFlag::DetectHidden), 0, "detect_hidden"},
        {to_int(AffectFlag::Talon), 0, "talon"},
        {to_int(AffectFlag::Sanctuary), 0, "sanctuary"},
        {to_int(AffectFlag::FaerieFire), 0, "faerie_fire"},
        {to_int(AffectFlag::Infrared), 0, "infrared"},
        {to_int(AffectFlag::Curse), 0, "curse"},
        {to_int(AffectFlag::ProtectionEvil), 0, "protection_evil"},
        {to_int(AffectFlag::Poison), 0, "poison"},
        {to_int(AffectFlag::ProtectionGood), 0, "protection_good"},
        {to_int(AffectFlag::Sneak), 0, "sneak"},
        {to_int(AffectFlag::Hide), 0, "hide"},
        {to_int(AffectFlag::Sleep), 0, "sleep"},
        {to_int(AffectFlag::Charm), 0, "charm"},
        {to_int(AffectFlag::Flying), 0, "flying"},
        {to_int(AffectFlag::PassDoor), 0, "pass_door"},
        {to_int(AffectFlag::Haste), 0, "haste"},
        {to_int(AffectFlag::Calm), 0, "calm"},
        {to_int(AffectFlag::Plague), 0, "plague"},
        {to_int(AffectFlag::Weaken), 0, "weaken"},
        {to_int(AffectFlag::DarkVision), 0, "dark_vision"},
        {to_int(AffectFlag::Berserk), 0, "berserk"},
        {to_int(AffectFlag::Swim), 0, "swim"},
        {to_int(AffectFlag::Regeneration), 0, "regeneration"},
        {to_int(AffectFlag::OctarineFire), 0, "octarine_fire"},
        {to_int(AffectFlag::Lethargy), 0, "lethargy"}
        // clang-format on
    }};
    inline static constexpr std::array<Flag, 22> AllCharActFlags = {{
        // clang-format off
        {to_int(CharActFlag::Npc), 0, "npc"},
        {to_int(CharActFlag::Sentinel), 0, "sentinel"},
        {to_int(CharActFlag::Scavenger), 0, "scavenger"},
        {to_int(CharActFlag::Aggressive), 0, "aggressive"},
        {to_int(CharActFlag::StayArea), 0, "stay_area"},
        {to_int(CharActFlag::Wimpy), 0, "wimpy"},
        {to_int(CharActFlag::Pet), 0, "pet"},
        {to_int(CharActFlag::Train), 0, "train"},
        {to_int(CharActFlag::Practice), 0, "practice"},
        {to_int(CharActFlag::Sentient), 0, "sentient"},
        {to_int(CharActFlag::Talkative), 0, "talkative"},
        {to_int(CharActFlag::Undead), 0, "undead"},
        {to_int(CharActFlag::Cleric), 0, "cleric"},
        {to_int(CharActFlag::Mage), 0, "mage"},
        {to_int(CharActFlag::Thief), 0, "thief"},
        {to_int(CharActFlag::Warrior), 0, "warrior"},
        {to_int(CharActFlag::NoAlign), 0, "no_align"},
        {to_int(CharActFlag::NoPurge), 0, "no_purge"},
        {to_int(CharActFlag::Healer), 0, "healer"},
        {to_int(CharActFlag::Gain), 0, "skill_train"},
        {to_int(CharActFlag::UpdateAlways), 0, "update_always"},
        {to_int(CharActFlag::CanBeRidden), 0, "rideable"}
        // clang-format on
    }};
    inline static constexpr std::array<Flag, 21> AllPlayerActFlags = {{
        // clang-format off
        {to_int(PlayerActFlag::PlrNpc), 0, "npc"}, // Only set for NPCs
        {to_int(PlayerActFlag::PlrBoughtPet), 0, "owner"},
        {to_int(PlayerActFlag::PlrAutoAssist), 0, "autoassist"},
        {to_int(PlayerActFlag::PlrAutoExit), 0, "autoexit"},
        {to_int(PlayerActFlag::PlrAutoLoot), 0, "autoloot"},
        {to_int(PlayerActFlag::PlrAutoSac), 0, "autosac"},
        {to_int(PlayerActFlag::PlrAutoGold), 0, "autogold"},
        {to_int(PlayerActFlag::PlrAutoSplit), 0, "autosplit"},
        {to_int(PlayerActFlag::PlrHolyLight), 0, "holy_light"},
        {to_int(PlayerActFlag::PlrWizInvis), 0, "wizinvis"},
        {to_int(PlayerActFlag::PlrCanLoot), 0, "loot_corpse"},
        {to_int(PlayerActFlag::PlrNoSummon), 0, "no_summon"},
        {to_int(PlayerActFlag::PlrNoFollow), 0, "no_follow"},
        {to_int(PlayerActFlag::PlrAfk), 0, "afk"},
        {to_int(PlayerActFlag::PlrLog), 0, "log"},
        {to_int(PlayerActFlag::PlrDeny), 0, "deny"},
        {to_int(PlayerActFlag::PlrFreeze), 0, "freeze"},
        {to_int(PlayerActFlag::PlrThief), 0, "thief"},
        {to_int(PlayerActFlag::PlrKiller), 0, "killer"},
        {to_int(PlayerActFlag::PlrAutoPeek), 0, "autopeek"},
        {to_int(PlayerActFlag::PlrProwl), 0, "prowl"}
        // clang-format on
    }};
    inline static constexpr std::array<Flag, 23> AllCommFlags = {{
        // clang-format off
        {to_int(CommFlag::Quiet), 0, "quiet"},
        {to_int(CommFlag::Deaf), 0, "deaf"},
        {to_int(CommFlag::NoWiz), 0, "no_wiz"},
        {to_int(CommFlag::NoAuction), 0, "no_action"},
        {to_int(CommFlag::NoGossip), 0, "no_gossip"},
        {to_int(CommFlag::NoQuestion), 0, "no_question"},
        {to_int(CommFlag::NoMusic), 0, "no_music"},
        {to_int(CommFlag::NoGratz), 0, "no_gratz"},
        {to_int(CommFlag::NoAnnounce), 0, "no_allege"},
        {to_int(CommFlag::NoPhilosophise), 0, "no_philosophise"},
        {to_int(CommFlag::NoQwest), 0, "no_qwest"},
        {to_int(CommFlag::Compact), 0, "compact"},
        {to_int(CommFlag::Brief), 0, "brief"},
        {to_int(CommFlag::Prompt), 0, "prompt"},
        {to_int(CommFlag::Combine), 0, "combine"},
        {to_int(CommFlag::ShowAfk), 0, "show_afk"},
        {to_int(CommFlag::ShowDefence), 0, "show_def"},
        {to_int(CommFlag::NoEmote), 0, "no_emote"},
        {to_int(CommFlag::NoYell), 0, "no_yell"},
        {to_int(CommFlag::NoTell), 0, "no_tell"},
        {to_int(CommFlag::NoChannels), 0, "no_channels"},
        {to_int(CommFlag::NoAllege), 0, "no_allege"},
        {to_int(CommFlag::Affect), 0, "affect"}
        // clang-format on
    }};
    inline static constexpr std::array<Flag, 23> AllOffensiveFlags = {{
        // clang-format off
        {to_int(OffensiveFlag::AreaAttack), 0, "area_attack"},
        {to_int(OffensiveFlag::Backstab), 0, "backstab"},
        {to_int(OffensiveFlag::Bash), 0, "bash"},
        {to_int(OffensiveFlag::Berserk), 0, "berserk"},
        {to_int(OffensiveFlag::Disarm), 0, "disarm"},
        {to_int(OffensiveFlag::Dodge), 0, "dodge"},
        {to_int(OffensiveFlag::Fade), 0, "fade"},
        {to_int(OffensiveFlag::Fast), 0, "fast"},
        {to_int(OffensiveFlag::Slow), 0, "slow"},
        {to_int(OffensiveFlag::Kick), 0, "kick"},
        {to_int(OffensiveFlag::KickDirt), 0, "kick_dirt"},
        {to_int(OffensiveFlag::Parry), 0, "parry"},
        {to_int(OffensiveFlag::Rescue), 0, "rescue"},
        {to_int(OffensiveFlag::Tail), 0, "tail"},
        {to_int(OffensiveFlag::Trip), 0, "trip"},
        {to_int(OffensiveFlag::Crush), 0, "crush"},
        {to_int(OffensiveFlag::AssistAll), 0, "assist_all"},
        {to_int(OffensiveFlag::AssistAlign), 0, "assist_align"},
        {to_int(OffensiveFlag::AssistRace), 0, "assist_race"},
        {to_int(OffensiveFlag::AssistPlayers), 0, "assist_players"},
        {to_int(OffensiveFlag::AssistGuard), 0, "assist_guard"},
        {to_int(OffensiveFlag::AssistVnum), 0, "assist_vnum"},
        {to_int(OffensiveFlag::Headbutt), 0, "headbutt"}
        // clang-format on
    }};

private:
    template <typename Func>
    [[nodiscard]] Object *find_filtered_obj(std::string_view argument, Func filter) const;
    [[nodiscard]] std::optional<std::string_view> delta_nutrition(const auto supplier, const sh_int delta) noexcept;
    static int num_active_;
};
