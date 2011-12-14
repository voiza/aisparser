/* -----------------------------------------------------------------------
   libuais vdm/vdo sentence parsing
   Copyright 2006-2008 by Brian C. Lane <bcl@brianlane.com>
   All rights Reserved
   ----------------------------------------------------------------------- */

/*! \file
    \brief Header file for vdm_parse.c

    Structures for each AIS message type
    and a structure to hold position information

    For exact definitions of each field you should see the ITU M.1371,
    IEC 62287 and the IALA Clarifications on M.1371
    The format of the !AIVDM strings are covered in IEC 61993-2
*/

/* Length of 6-bit data buffer */
#define SIXBUF_LEN  255


/** AIS Message 1 - Position Report with SOTDMA
*/
typedef enum {
    e_aismsg_1_nav_status       = 1 << 0,   //!< Navigational Status
    e_aismsg_1_rot              = 1 << 1,   //!< Rate of Turn
    e_aismsg_1_sog              = 1 << 2,   //!< Speed Over ground
    e_aismsg_1_pos_acc          = 1 << 3,   //!< Position Accuracy
    e_aismsg_1_longitude        = 1 << 4,   //!< Longitude in 1/10000 minute
    e_aismsg_1_latitude         = 1 << 5,   //!< Latitude in 1/10000 minute
    e_aismsg_1_cog              = 1 << 6,   //!< Course over Ground in 1/10 degree
    e_aismsg_1_true_heading     = 1 << 7,   //!< True Heading
    e_aismsg_1_utc_sec          = 1 << 8,   //!< UTC Seconds
    e_aismsg_1_regional         = 1 << 9,   //!< Regional bits
    e_aismsg_1_spare            = 1 << 10,  //!< Spare
    e_aismsg_1_raim             = 1 << 11,  //!< RAIM flag
    e_aismsg_1_sync_state       = 1 << 12,  //!< SOTDMA sync state
    e_aismsg_1_slot_timeout     = 1 << 13,  //!< SOTDMA Slot Timeout
    e_aismsg_1_sub_message      = 1 << 14,  //!< SOTDMA sub-message
} aismsg_1_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits  : Message ID (1)
    char            repeat;            //!< 2 bits  : Repeated
    unsigned long   userid;            //!< 30 bits : UserID / MMSI    
    unsigned char   nav_status;        //!< 4 bits  : Navigational Status
    char            rot;               //!< 8 bits  : Rate of Turn   
    int             sog;               //!< 10 bits : Speed Over Ground
    char            pos_acc;           //!< 1 bit   : Position Accuracy
    long            longitude;         //!< 28 bits : Longitude in 1/10000 minute
    long            latitude;          //!< 27 bits : Latitude in 1/10000 minute
    int             cog;               //!< 12 bits : Course over Ground in 1/10 degree
    int             true_heading;      //!< 9 bits  : True heading
    char            utc_sec;           //!< 6 bits  : UTC Seconds
    char            regional;          //!< 4 bits  : Regional bits
    char            spare;             //!< 1 bit   : Spare
    char            raim;              //!< 1 bit   : RAIM flag
    char            sync_state;        //!< 2 bits  : SOTDMA sync state
    char            slot_timeout;      //!< 3 bits  : SOTDMA Slot Timeout
    int             sub_message;       //!< 14 bits : SOTDMA sub-message
    aismsg_1_invalidity_mask mask;     //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_1;


/** AIS Message 2 - Position Report with SOTDMA
*/
typedef enum {
    e_aismsg_2_nav_status       = 1 << 0,   //!< Navigational Status
    e_aismsg_2_rot              = 1 << 1,   //!< Rate of Turn
    e_aismsg_2_sog              = 1 << 2,   //!< Speed Over ground
    e_aismsg_2_pos_acc          = 1 << 3,   //!< Position Accuracy
    e_aismsg_2_longitude        = 1 << 4,   //!< Longitude in 1/10000 minute
    e_aismsg_2_latitude         = 1 << 5,   //!< Latitude in 1/10000 minute
    e_aismsg_2_cog              = 1 << 6,   //!< Course over Ground in 1/10 degree
    e_aismsg_2_true_heading     = 1 << 7,   //!< True Heading
    e_aismsg_2_utc_sec          = 1 << 8,   //!< UTC Seconds
    e_aismsg_2_regional         = 1 << 9,   //!< Regional bits
    e_aismsg_2_spare            = 1 << 10,  //!< Spare
    e_aismsg_2_raim             = 1 << 11,  //!< RAIM flag
    e_aismsg_2_sync_state       = 1 << 12,  //!< SOTDMA sync state
    e_aismsg_2_slot_timeout     = 1 << 13,  //!< SOTDMA Slot Timeout
    e_aismsg_2_sub_message      = 1 << 14,  //!< SOTDMA sub-message
} aismsg_2_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits  : Message ID (2)
    char            repeat;            //!< 2 bits  : Repeated
    unsigned long   userid;            //!< 30 bits : UserID / MMSI
    unsigned char   nav_status;        //!< 4 bits  : Navigational Status
    char            rot;               //!< 8 bits  : Rate of Turn
    int             sog;               //!< 10 bits : Speed Over ground
    char            pos_acc;           //!< 1 bit   : Position Accuracy
    long            longitude;         //!< 28 bits : Longitude in 1/10000 minute
    long            latitude;          //!< 27 bits : Latitude in 1/10000 minute
    int             cog;               //!< 12 bits : Course over Ground in 1/10 degree
    int             true_heading;      //!< 9 bits  : True Heading
    char            utc_sec;           //!< 6 bits  : UTC Seconds
    char            regional;          //!< 4 bits  : Regional bits
    char            spare;             //!< 1 bit   : Spare
    char            raim;              //!< 1 bit   : RAIM flag
    char            sync_state;        //!< 2 bits  : SOTDMA sync state
    char            slot_timeout;      //!< 3 bits  : SOTDMA Slot Timeout
    int             sub_message;       //!< 14 bits : SOTDMA sub-message
    aismsg_2_invalidity_mask mask;     //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_2;


/** AIS Message 3 - Position Report with ITDMA
*/
typedef enum {
    e_aismsg_3_nav_status       = 1 << 0,   //!< Navigational Status
    e_aismsg_3_rot              = 1 << 1,   //!< Rate of Turn
    e_aismsg_3_sog              = 1 << 2,   //!< Speed Over Ground
    e_aismsg_3_pos_acc          = 1 << 3,   //!< Position Accuracy
    e_aismsg_3_longitude        = 1 << 4,   //!< Longitude in 1/10000 minute
    e_aismsg_3_latitude         = 1 << 5,   //!< Latitude in 1/10000 minute
    e_aismsg_3_cog              = 1 << 6,   //!< Course over Ground in 1/10 degree
    e_aismsg_3_true_heading     = 1 << 7,   //!< True Heading
    e_aismsg_3_utc_sec          = 1 << 8,   //!< UTC Seconds
    e_aismsg_3_regional         = 1 << 9,   //!< Regional bits
    e_aismsg_3_spare            = 1 << 10,  //!< Spare
    e_aismsg_3_raim             = 1 << 11,  //!< RAIM Flag
    e_aismsg_3_sync_state       = 1 << 12,  //!< ITDMA sync state
    e_aismsg_3_slot_increment   = 1 << 13,  //!< ITDMA Slot Increment
    e_aismsg_3_num_slots        = 1 << 14,  //!< ITDMA Number of Slots
    e_aismsg_3_keep             = 1 << 15,  //!< ITDMA Keep Flag
} aismsg_3_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits  : MessageID (3)
    char            repeat;            //!< 2 bits  : Repeated
    unsigned long   userid;            //!< 30 bits : UserID / MMSI
    unsigned char   nav_status;        //!< 4 bits  : Navigational Status
    char            rot;               //!< 8 bits  : Rate of Turn
    int             sog;               //!< 10 bits : Speed Over Ground
    char            pos_acc;           //!< 1 bit   : Position Accuracy
    long            longitude;         //!< 28 bits : Longitude in 1/10000 minute
    long            latitude;          //!< 27 bits : Latitude in 1/10000 minute
    int             cog;               //!< 12 bits : Course over Ground in 1/10 degree
    int             true_heading;      //!< 9 bits  : True Heading
    char            utc_sec;           //!< 6 bits  : UTC Seconds
    char            regional;          //!< 4 bits  : Regional bits
    char            spare;             //!< 1 bit   : Spare
    char            raim;              //!< 1 bit   : RAIM Flag
    char            sync_state;        //!< 2 bits  : ITDMA sync state
    int             slot_increment;    //!< 13 bits : ITDMA Slot Increment
    char            num_slots;         //!< 3 bits  : ITDMA Number of Slots
    char            keep;              //!< 1 bit   : ITDMA Keep Flag
    aismsg_3_invalidity_mask mask;     //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_3;


/** AIS Message 4 - Base Station Report
*/
typedef enum {
    e_aismsg_4_utc_year         = 1 << 0,   //!< UTC Year
    e_aismsg_4_utc_month        = 1 << 1,   //!< UTC Month
    e_aismsg_4_utc_day          = 1 << 2,   //!< UTC Day
    e_aismsg_4_utc_hour         = 1 << 3,   //!< UTC Hour
    e_aismsg_4_utc_minute       = 1 << 4,   //!< UTC Minute
    e_aismsg_4_utc_second       = 1 << 5,   //!< UTC Second
    e_aismsg_4_pos_acc          = 1 << 6,   //!< Position Accuracy
    e_aismsg_4_longitude        = 1 << 7,   //!< Longitude in 1/10000 minute
    e_aismsg_4_latitude         = 1 << 8,   //!< Latitude in 1/10000 minute
    e_aismsg_4_pos_type         = 1 << 9,   //!< Type of position fixing device
    e_aismsg_4_spare            = 1 << 10,  //!< Spare
    e_aismsg_4_raim             = 1 << 11,  //!< RAIM flag
    e_aismsg_4_sync_state       = 1 << 12,  //!< SOTDMA sync state
    e_aismsg_4_slot_timeout     = 1 << 13,  //!< SOTDMA Slot Timeout
    e_aismsg_4_sub_message      = 1 << 14,  //!< SOTDMA sub-message
} aismsg_4_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits  : MessageID (4)
    char            repeat;            //!< 2 bits  : Repeated
    unsigned long   userid;            //!< 30 bits : UserID / MMSI
    int             utc_year;          //!< 14 bits : UTC Year
    char            utc_month;         //!< 4 bits  : UTC Month
    char            utc_day;           //!< 5 bits  : UTC Day
    char            utc_hour;          //!< 5 bits  : UTC Hour
    char            utc_minute;        //!< 6 bits  : UTC Minute
    char            utc_second;        //!< 6 bits  : UTC Second
    char            pos_acc;           //!< 1 bit   : Position Accuracy
    long            longitude;         //!< 28 bits : Longitude in 1/10000 minute
    long            latitude;          //!< 27 bits : Latitude in 1/10000 minute
    char            pos_type;          //!< 4 bits  : Type of position fixing device
    int             spare;             //!< 10 bits : Spare
    char            raim;              //!< 1 bit   : RAIM flag
    char            sync_state;        //!< 2 bits  : SOTDMA sync state
    char            slot_timeout;      //!< 3 bits  : SOTDMA Slot Timeout
    int             sub_message;       //!< 14 bits : SOTDMA sub-message
    aismsg_4_invalidity_mask mask;     //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_4;


/** AIS Message 5 - Ship static and voyage related data
*/
typedef enum {
    e_aismsg_5_version          = 1 << 0,   //!< AIS Version
    e_aismsg_5_imo              = 1 << 1,   //!< IMO Number
    e_aismsg_5_callsign         = 1 << 2,   //!< Callsign
    e_aismsg_5_name             = 1 << 3,   //!< Ship Name
    e_aismsg_5_ship_type        = 1 << 4,   //!< Type of Ship and Cargo
    e_aismsg_5_dim_bow          = 1 << 5,   //!< GPS Ant. Distance from Bow
    e_aismsg_5_dim_stern        = 1 << 6,   //!< GPS Ant. Distance from stern
    e_aismsg_5_dim_port         = 1 << 7,   //!< GPS Ant. Distance from port
    e_aismsg_5_dim_starboard    = 1 << 8,   //!< GPS Ant. Distance from starboard
    e_aismsg_5_pos_type         = 1 << 9,   //!< Type of position fixing device
    e_aismsg_5_eta_minute       = 1 << 10,  //!< Minute of Estimated Time of Arrival
    e_aismsg_5_eta_hour         = 1 << 11,  //!< Hour of Estimated Time of Arrival
    e_aismsg_5_eta_day          = 1 << 12,  //!< Day of Estimated Time of Arrival
    e_aismsg_5_eta_month        = 1 << 13,  //!< Month of Estimated Time of Arrival
    e_aismsg_5_draught          = 1 << 14,  //!< Maximum present static draught
    e_aismsg_5_dest             = 1 << 15,  //!< Ship Destination
    e_aismsg_5_dte              = 1 << 16,  //!< DTE flag
    e_aismsg_5_spare            = 1 << 17,  //!< spare
} aismsg_5_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits  : MessageID (5)
    char            repeat;            //!< 2 bits  : Repeated
    unsigned long   userid;            //!< 30 bits : UserID / MMSI
    char            version;           //!< 2 bits  : AIS Version
    unsigned long   imo;               //!< 30 bits : IMO Number
    char            callsign[8];       //!< 7x6 (42) bits : Callsign
    char            name[21];          //!< 20x6 (120) bits : Ship Name
    unsigned char   ship_type;         //!< 8 bits  : Type of Ship and Cargo
    int             dim_bow;           //!< 9 bits  : GPS Ant. Distance from Bow
    int             dim_stern;         //!< 9 bits  : GPS Ant. Distance from stern
    char            dim_port;          //!< 6 bits  : GPS Ant. Distance from port
    char            dim_starboard;     //!< 6 bits  : GPS Ant. Distance from starboard
    char            pos_type;          //!< 4 bits  : Type of position fixing device
    unsigned char   eta_minute;        //!< 5 bits  : Estimated minute of Time of Arrival
    unsigned char   eta_hour;          //!< 5 bits  : Estimated hour of Time of Arrival
    unsigned char   eta_day;           //!< 5 bits  : Estimated day of Time of Arrival
    unsigned char   eta_month;         //!< 5 bits  : Estimated month of Time of Arrival
//    unsigned long   eta;               //!< 20 bits : Estimated Time of Arrival MMDDHHMM
    unsigned char   draught;           //!< 8 bits  : Maximum present static draught
    char            dest[21];          //!< 6x20 (120) bits : Ship Destination
    char            dte;               //!< 1 bit   : DTE flag
    char            spare;             //!< 1 bit   : spare
    aismsg_5_invalidity_mask mask;     //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_5;


/** AIS Message 6 - Addressed Binary Message
*/
typedef enum {
    e_aismsg_6_sequence         = 1 << 0,   //!< Sequence number
    e_aismsg_6_destination      = 1 << 1,   //!< Destination MMSI
    e_aismsg_6_retransmit       = 1 << 2,   //!< Retransmit
    e_aismsg_6_spare            = 1 << 3,   //!< Spare
    e_aismsg_6_app_id           = 1 << 4,   //!< Application ID
    e_aismsg_6_data             = 1 << 5,   //!< Data payload
} aismsg_6_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (6)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            sequence;          //!< 2 bits   : Sequence number
    unsigned long   destination;       //!< 30 bits  : Destination MMSI
    char            retransmit;        //!< 1 bit    : Retransmit
    char            spare;             //!< 1 bit    : Spare
    unsigned int    app_id;            //!< 16 bits  : Application ID
    sixbit          data;              //!< 960 bits : Data payload
    aismsg_6_invalidity_mask mask;     //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_6;


/** AIS Message 7 - Binary Acknowledge
*/
typedef enum {
    e_aismsg_7_spare            = 1 << 0,   //!< Spare
    e_aismsg_7_destid_1         = 1 << 1,   //!< Destination MMSI 1
    e_aismsg_7_sequence_1       = 1 << 2,   //!< Sequence Number 1
    e_aismsg_7_destid_2         = 1 << 3,   //!< Destination MMSI 2
    e_aismsg_7_sequence_2       = 1 << 4,   //!< Sequence Number 2
    e_aismsg_7_destid_3         = 1 << 5,   //!< Destination MMSI 3
    e_aismsg_7_sequence_3       = 1 << 6,   //!< Sequence Number 3
    e_aismsg_7_destid_4         = 1 << 7,   //!< Destination MMSI 4
    e_aismsg_7_sequence_4       = 1 << 8,   //!< Sequence Number 4
    e_aismsg_7_num_acks         = 1 << 9,   //!< Number of acks 
} aismsg_7_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (7)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            spare;             //!< 2 bits   : Spare
    unsigned long   destid_1;          //!< 30 bits  : Destination MMSI 1
    char            sequence_1;        //!< 2 bits   : Sequence Number 1
    unsigned long   destid_2;          //!< 30 bits  : Destination MMSI 2
    char            sequence_2;        //!< 2 bits   : Sequence Number 2
    unsigned long   destid_3;          //!< 30 bits  : Destination MMSI 3
    char            sequence_3;        //!< 2 bits   : Sequence Number 3
    unsigned long   destid_4;          //!< 30 bits  : Destination MMSI 4
    char            sequence_4;        //!< 2 bits   : Sequence Number 4
    char            num_acks;          //!< Number of acks 
    aismsg_7_invalidity_mask mask;     //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_7;


/** AIS Message 8 - Binary Broadcast Message
*/
typedef enum {
    e_aismsg_8_spare            = 1 << 0,   //!< Spare
    e_aismsg_8_app_id           = 1 << 1,   //!< Application ID
    e_aismsg_8_data             = 1 << 2,   //!< Data payload
} aismsg_8_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (8)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            spare;             //!< 2 bits   : Spare
    unsigned int    app_id;            //!< 16 bits  : Application ID
    sixbit          data;              //!< 952 bits : Data payload
    aismsg_8_invalidity_mask mask;     //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_8;


/** AIS Message 9 - Standard SAR Aircraft position report
*/
typedef enum {
    e_aismsg_9_altitude         = 1 << 0,   //!< Altitude
    e_aismsg_9_sog              = 1 << 1,   //!< Speed Over Ground
    e_aismsg_9_pos_acc          = 1 << 2,   //!< Position Accuracy
    e_aismsg_9_longitude        = 1 << 3,   //!< Longitude in 1/10000 minute
    e_aismsg_9_latitude         = 1 << 4,   //!< Latitude in 1/10000 minute
    e_aismsg_9_cog              = 1 << 5,   //!< Course Over Ground in 1/10 degree
    e_aismsg_9_utc_sec          = 1 << 6,   //!< UTC Seconds
    e_aismsg_9_regional         = 1 << 7,   //!< Regional bits
    e_aismsg_9_dte              = 1 << 8,   //!< DTE flag
    e_aismsg_9_spare            = 1 << 9,   //!< Spare
    e_aismsg_9_assigned         = 1 << 10,  //!< Assigned mode flag
    e_aismsg_9_raim             = 1 << 11,  //!< RAIM flag
    e_aismsg_9_comm_state       = 1 << 12,  //!< Comm State Flag
    e_aismsg_9_sotdma           = 1 << 13,  //!< sotdma
    e_aismsg_9_itdma            = 1 << 14,  //!< itdma
} aismsg_9_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (9)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    int             altitude;          //!< 12 bits  : Altitude
    int             sog;               //!< 10 bits  : Speed Over Ground
    char            pos_acc;           //!< 1 bit    : Position Accuracy
    long            longitude;         //!< 28 bits  : Longitude in 1/10000 minute
    long            latitude;          //!< 27 bits  : Latitude in 1/10000 minute
    int             cog;               //!< 12 bits  : Course Over Ground in 1/10 degree
    char            utc_sec;           //!< 6 bits   : UTC Seconds
    unsigned char   regional;          //!< 8 bits   : Regional bits
    char            dte;               //!< 1 bit    : DTE flag
    char            spare;             //!< 3 bits   : Spare
    char            assigned;          //!< 1 bit    : Assigned mode flag
    char            raim;              //!< 1 bit    : RAIM flag
    char            comm_state;        //!< 1 bit    : Comm State Flag
    struct {
        char          sync_state;      //!< 2 bits   : SOTDMA Sync State
        char          slot_timeout;    //!< 3 bits   : SOTDMA Slot Timeout
        int           sub_message;     //!< 14 bits  : SOTDMA Sub-Messsage
    } sotdma;
    struct {
        char          sync_state;      //!< 2 bits   : ITDMA Sync State
        int           slot_inc;        //!< 13 bits  : ITDMA Slot Increment
        char          num_slots;       //!< 3 bits   : ITDMA Number of Slots
        char          keep_flag;       //!< 1 bit    : ITDMA Keep Flag
    } itdma;
    aismsg_9_invalidity_mask mask;     //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_9;


/** AIS Message 10 - UTC and Date inquiry
*/
typedef enum {
    e_aismsg_10_spare1          = 1 << 0,   //!< Spare
    e_aismsg_10_destination     = 1 << 1,   //!< Destination MMSI
    e_aismsg_10_spare2          = 1 << 2,   //!< Spare
} aismsg_10_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (10)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            spare1;            //!< 2 bits   : Spare
    unsigned long   destination;       //!< 30 bits  : Destination MMSI
    char            spare2;            //!< 2 bits   : Spare
    aismsg_10_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_10;


/** AIS Message 11 - UTC and Date response
*/
typedef enum {
    e_aismsg_11_utc_year        = 1 << 0,   //!< UTC Year
    e_aismsg_11_utc_month       = 1 << 1,   //!< UTC Month
    e_aismsg_11_utc_day         = 1 << 2,   //!< UTC Day
    e_aismsg_11_utc_hour        = 1 << 3,   //!< UTC Hour
    e_aismsg_11_utc_minute      = 1 << 4,   //!< UTC Minute
    e_aismsg_11_utc_second      = 1 << 5,   //!< UTC Second
    e_aismsg_11_pos_acc         = 1 << 6,   //!< Position Accuracy
    e_aismsg_11_longitude       = 1 << 7,   //!< Longitude in 1/10000 minute
    e_aismsg_11_latitude        = 1 << 8,   //!< Latitude in 1/10000 minute
    e_aismsg_11_pos_type        = 1 << 9,   //!< Type of position fixing device
    e_aismsg_11_spare           = 1 << 10,  //!< Spare
    e_aismsg_11_raim            = 1 << 11,  //!< RAIM flag
    e_aismsg_11_sync_state      = 1 << 12,  //!< SOTDMA sync state
    e_aismsg_11_slot_timeout    = 1 << 13,  //!< SOTDMA Slot Timeout
    e_aismsg_11_sub_message     = 1 << 14,  //!< SOTDMA sub-message
} aismsg_11_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits  : MessageID (4)
    char            repeat;            //!< 2 bits  : Repeated
    unsigned long   userid;            //!< 30 bits : UserID / MMSI
    int             utc_year;          //!< 14 bits : UTC Year
    char            utc_month;         //!< 4 bits  : UTC Month
    char            utc_day;           //!< 5 bits  : UTC Day
    char            utc_hour;          //!< 5 bits  : UTC Hour
    char            utc_minute;        //!< 6 bits  : UTC Minute
    char            utc_second;        //!< 6 bits  : UTC Second
    char            pos_acc;           //!< 1 bit   : Position Accuracy
    long            longitude;         //!< 28 bits : Longitude in 1/10000 minute
    long            latitude;          //!< 27 bits : Latitude in 1/10000 minute
    char            pos_type;          //!< 4 bits  : Type of position fixing device
    int             spare;             //!< 10 bits : Spare
    char            raim;              //!< 1 bit   : RAIM flag
    char            sync_state;        //!< 2 bits  : SOTDMA sync state
    char            slot_timeout;      //!< 3 bits  : SOTDMA Slot Timeout
    int             sub_message;       //!< 14 bits : SOTDMA sub-message
    aismsg_11_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_11;


/** AIS Message 12 - Addressed safety related message
*/
typedef enum {
    e_aismsg_12_sequence        = 1 << 0,   //!< Sequence
    e_aismsg_12_destination     = 1 << 1,   //!< Destination MMSI
    e_aismsg_12_retransmit      = 1 << 2,   //!< Retransmit
    e_aismsg_12_spare           = 1 << 3,   //!< Spare
    e_aismsg_12_message         = 1 << 4,   //!< Message in ASCII   
} aismsg_12_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (12)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            sequence;          //!< 2 bits   : Sequence
    unsigned long   destination;       //!< 30 bits  : Destination MMSI
    char            retransmit;        //!< 1 bit    : Retransmit
    char            spare;             //!< 1 bit    : Spare
    char            message[158];      //!< 936 bits : Message in ASCII   
    aismsg_12_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_12;


/** AIS Message 13 - Safety related Acknowledge
*/
typedef enum {
    e_aismsg_13_spare           = 1 << 0,   //!< Spare
    e_aismsg_13_destid_1        = 1 << 1,   //!< Destination MMSI 1
    e_aismsg_13_sequence_1      = 1 << 2,   //!< Sequence Number 1
    e_aismsg_13_destid_2        = 1 << 3,   //!< Destination MMSI 2
    e_aismsg_13_sequence_2      = 1 << 4,   //!< Sequence Number 2
    e_aismsg_13_destid_3        = 1 << 5,   //!< Destination MMSI 3
    e_aismsg_13_sequence_3      = 1 << 6,   //!< Sequence Number 3
    e_aismsg_13_destid_4        = 1 << 7,   //!< Destination MMSI 4
    e_aismsg_13_sequence_4      = 1 << 8,   //!< Sequence Number 4
    e_aismsg_13_num_acks        = 1 << 9,   //!< Number of acks 
} aismsg_13_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (13)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            spare;             //!< 2 bits   : Spare
    unsigned long   destid_1;          //!< 30 bits  : Destination MMSI 1
    char            sequence_1;        //!< 2 bits   : Sequence Number 1
    unsigned long   destid_2;          //!< 30 bits  : Destination MMSI 2
    char            sequence_2;        //!< 2 bits   : Sequence Number 2
    unsigned long   destid_3;          //!< 30 bits  : Destination MMSI 3
    char            sequence_3;        //!< 2 bits   : Sequence Number 3
    unsigned long   destid_4;          //!< 30 bits  : Destination MMSI 4
    char            sequence_4;        //!< 2 bits   : Sequence Number 4
    char            num_acks;          //!< Number of acks 
    aismsg_13_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_13;


/** AIS Message 14 - Safety related Broadcast Message
*/
typedef enum {
    e_aismsg_14_spare           = 1 << 0,   //!< Spare
    e_aismsg_14_message         = 1 << 1,   //!< Message in ASCII
} aismsg_14_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (14)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            spare;             //!< 2 bits   : Spare
    char            message[164];      //!< 968 bits : Message in ASCII
    aismsg_14_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_14;


/** AIS Message 15 - Interrogation
*/
typedef enum {
    e_aismsg_15_spare1         = 1 << 0,   //!< 2 bits   : Spare
    e_aismsg_15_destid1        = 1 << 1,   //!< 30 bits  : Destination MMSI 1
    e_aismsg_15_msgid1_1       = 1 << 2,   //!< 6 bits   : MessageID 1.1
    e_aismsg_15_offset1_1      = 1 << 3,   //!< 12 bits  : Slot Offset 1.1
    e_aismsg_15_spare2         = 1 << 4,   //!< 2 bits   : Spare
    e_aismsg_15_msgid1_2       = 1 << 5,   //!< 6 bits   : MessageID 1.2
    e_aismsg_15_offset1_2      = 1 << 6,   //!< 12 bits  : Slot Offset 1.2
    e_aismsg_15_spare3         = 1 << 7,   //!< 2 bits   : Spare
    e_aismsg_15_destid2        = 1 << 8,   //!< 30 bits  : Destination MMSI 2
    e_aismsg_15_msgid2_1       = 1 << 9,   //!< 6 bits   : MessageID 2.1
    e_aismsg_15_offset2_1      = 1 << 10,  //!< 12 bits  : Slot Offset 2.1
    e_aismsg_15_spare4         = 1 << 11,  //!< 2 bits   : Spare
    e_aismsg_15_num_reqs       = 1 << 12,  //!< Number of interrogation requests           
} aismsg_15_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (15)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            spare1;            //!< 2 bits   : Spare
    unsigned long   destid1;           //!< 30 bits  : Destination MMSI 1
    char            msgid1_1;          //!< 6 bits   : MessageID 1.1
    int             offset1_1;         //!< 12 bits  : Slot Offset 1.1
    char            spare2;            //!< 2 bits   : Spare
    char            msgid1_2;          //!< 6 bits   : MessageID 1.2
    int             offset1_2;         //!< 12 bits  : Slot Offset 1.2
    char            spare3;            //!< 2 bits   : Spare
    unsigned long   destid2;           //!< 30 bits  : Destination MMSI 2
    char            msgid2_1;          //!< 6 bits   : MessageID 2.1
    int             offset2_1;         //!< 12 bits  : Slot Offset 2.1
    char            spare4;            //!< 2 bits   : Spare
    char            num_reqs;          //!< Number of interrogation requests           
    aismsg_15_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_15;


/** AIS Message 16 - Assigned Mode Command
*/
typedef enum {
    e_aismsg_16_spare1          = 1 << 0,   //!< Spare
    e_aismsg_16_destid_a        = 1 << 1,   //!< Destination MMSI A
    e_aismsg_16_offset_a        = 1 << 2,   //!< Slot Offset A
    e_aismsg_16_increment_a     = 1 << 3,   //!< Increment A
    e_aismsg_16_destid_b        = 1 << 4,   //!< Destination MMSI B
    e_aismsg_16_offset_b        = 1 << 5,   //!< Slot Offset B
    e_aismsg_16_increment_b     = 1 << 6,   //!< Increment B
    e_aismsg_16_spare2          = 1 << 7,   //!< Spare
    e_aismsg_16_num_cmds        = 1 << 8,   //!< Number of commands received
} aismsg_16_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (16)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            spare1;            //!< 2 bits   : Spare
    unsigned long   destid_a;          //!< 30 bits  : Destination MMSI A
    int             offset_a;          //!< 12 bits  : Slot Offset A
    int             increment_a;       //!< 10 bits  : Increment A
    unsigned long   destid_b;          //!< 30 bits  : Destination MMSI B
    int             offset_b;          //!< 12 bits  : Slot Offset B
    int             increment_b;       //!< 10 bits  : Increment B
    char            spare2;            //!< 4 bits   : Spare
    char            num_cmds;          //!< Number of commands received
    aismsg_16_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_16;


/** AIS Message 17 - GNSS Binary Broadcast Message
*/
typedef enum {
    e_aismsg_17_spare1          = 1 << 0,   //!< Spare
    e_aismsg_17_longitude       = 1 << 1,   //!< Longitude in 1/1000 minute
    e_aismsg_17_latitude        = 1 << 2,   //!< Latitude in 1/1000 minute
    e_aismsg_17_spare2          = 1 << 3,   //!< Spare
    e_aismsg_17_msg_type        = 1 << 4,   //!< Mesage Type from M.823
    e_aismsg_17_station_id      = 1 << 5,   //!< Station ID from M.823
    e_aismsg_17_z_count         = 1 << 6,   //!< Z Count
    e_aismsg_17_seq_num         = 1 << 7,   //!< Sequence Number
    e_aismsg_17_num_words       = 1 << 8,   //!< Number of Data Words
    e_aismsg_17_health          = 1 << 9,   //!< Reference Station Health from M.823
    e_aismsg_17_data            = 1 << 10,  //!< Data payload
} aismsg_17_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (17)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            spare1;            //!< 2 bits   : Spare
    long            longitude;         //!< 18 bits  : Longitude in 1/1000 minute
    long            latitude;          //!< 17 bits  : Latitude in 1/1000 minute
    char            spare2;            //!< 5 bits   : Spare
    char            msg_type;          //!< 6 bits   : Message Type from M.823
    int             station_id;        //!< 10 bits  : Station ID from M.823
    int             z_count;           //!< 13 bits  : Z Count
    char            seq_num;           //!< 3 bits   : Sequence Number
    char            num_words;         //!< 5 bits   : Number of Data Words
    char            health;            //!< 3 bits   : Reference Station Health from M.823
    sixbit          data;              //!< 0-696 bits  : Data payload
    aismsg_17_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_17;


/** AIS Message 18 - Standard Class B CS Position Report

    From IEC 62287. This differs slightly from the original
    message, some of the regional bits were changed to flags.
*/
typedef enum {
    e_aismsg_18_regional1       = 1 << 0,   //!< Regional Bits
    e_aismsg_18_sog             = 1 << 1,   //!< Speed Over Ground
    e_aismsg_18_pos_acc         = 1 << 2,   //!< Position Accuracy
    e_aismsg_18_longitude       = 1 << 3,   //!< Longitude in 1/10000 minute
    e_aismsg_18_latitude        = 1 << 4,   //!< Latitude in 1/10000 minute
    e_aismsg_18_cog             = 1 << 5,   //!< Course Over Ground in 1/10 degree
    e_aismsg_18_true_heading    = 1 << 6,   //!< True Heading
    e_aismsg_18_utc_sec         = 1 << 7,   //!< UTC Seconds
    e_aismsg_18_regional2       = 1 << 8,   //!< Regional Bits
    e_aismsg_18_unit_flag       = 1 << 9,   //!< Class B CS Flag
    e_aismsg_18_display_flag    = 1 << 10,  //!< Integrated msg14 Display Flag
    e_aismsg_18_dsc_flag        = 1 << 11,  //!< DSC Capability flag
    e_aismsg_18_band_flag       = 1 << 12,  //!< Marine Band Operation Flag
    e_aismsg_18_msg22_flag      = 1 << 13,  //!< Msg22 Frequency Management Flag
    e_aismsg_18_mode_flag       = 1 << 14,  //!< Autonomous Mode Flag
    e_aismsg_18_raim            = 1 << 15,  //!< RAIM Flag
    e_aismsg_18_comm_state      = 1 << 16,  //!< Comm State Flag
    e_aismsg_18_sotdma          = 1 << 17,  //!< sotdma
    e_aismsg_18_itdma           = 1 << 18,  //!< itdma
} aismsg_18_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (18)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    unsigned char   regional1;         //!< 8 bits   : Regional Bits
    int             sog;               //!< 10 bits  : Speed Over Ground
    char            pos_acc;           //!< 1 bit    : Position Accuracy
    long            longitude;         //!< 28 bits  : Longitude in 1/10000 minute
    long            latitude;          //!< 27 bits  : Latitude in 1/10000 minute
    int             cog;               //!< 12 bits  : Course Over Ground in 1/10 degree
    int             true_heading;      //!< 9 bits   : True Heading
    char            utc_sec;           //!< 6 bits   : UTC Seconds
    char            regional2;         //!< 2 bits   : Regional Bits
    char            unit_flag;         //!< 1 bit    : Class B CS Flag
    char            display_flag;      //!< 1 bit    : Integrated msg14 Display Flag
    char            dsc_flag;          //!< 1 bit    : DSC Capability flag
    char            band_flag;         //!< 1 bit    : Marine Band Operation Flag
    char            msg22_flag;        //!< 1 bit    : Msg22 Frequency Management Flag
    char            mode_flag;         //!< 1 bit    : Autonomous Mode Flag
    char            raim;              //!< 1 bit    : RAIM Flag
    char            comm_state;        //!< 1 bit    : Comm State Flag
    struct {
        char          sync_state;      //!< 2 bits   : SOTDMA Sync State
        char          slot_timeout;    //!< 3 bits   : SOTDMA Slot Timeout
        int           sub_message;     //!< 14 bits  : SOTDMA Sub-Message
    } sotdma;
    struct {
        char          sync_state;      //!< 2 bits   : ITDMA Sync State
        int           slot_inc;        //!< 13 bits  : ITDMA Slot Increment
        char          num_slots;       //!< 3 bits   : ITDMA Number of Slots
        char          keep_flag;       //!< 1 bit    : ITDMA Keep Flag
    } itdma;
    aismsg_18_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_18;


/** AIS Message 19 - Extended Class B Equipment Position Report
*/
typedef enum {
    e_aismsg_19_regional1       = 1 << 0,   //!< Regional Bits
    e_aismsg_19_sog             = 1 << 1,   //!< Speed Over Ground
    e_aismsg_19_pos_acc         = 1 << 2,   //!< Position Accuracy
    e_aismsg_19_longitude       = 1 << 3,   //!< Longitude in 1/10000 minute
    e_aismsg_19_latitude        = 1 << 4,   //!< Latitude in 1/10000 minute
    e_aismsg_19_cog             = 1 << 5,   //!< Course Over Ground in 1/10 degree
    e_aismsg_19_true_heading    = 1 << 6,   //!< True Heading
    e_aismsg_19_utc_sec         = 1 << 7,   //!< UTC Seconds
    e_aismsg_19_regional2       = 1 << 8,   //!< Regional Bits
    e_aismsg_19_name            = 1 << 9,   //!< Ship Name in ASCII
    e_aismsg_19_ship_type       = 1 << 10,  //!< Type of Ship and Cargo
    e_aismsg_19_dim_bow         = 1 << 11,  //!< GPS Ant. Distance from Bow
    e_aismsg_19_dim_stern       = 1 << 12,  //!< GPS Ant. Distance from Stern   
    e_aismsg_19_dim_port        = 1 << 13,  //!< GPS Ant. Distance from Port
    e_aismsg_19_dim_starboard   = 1 << 14,  //!< GPS Ant. Distance from Starboard
    e_aismsg_19_pos_type        = 1 << 15,  //!< Type of Position Fixing Device
    e_aismsg_19_raim            = 1 << 16,  //!< RAIM Flag
    e_aismsg_19_dte             = 1 << 17,  //!< DTE Flag
    e_aismsg_19_spare           = 1 << 18,  //!< Spare
} aismsg_19_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (19)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            regional1;         //!< 8 bits   : Regional Bits
    int             sog;               //!< 10 bits  : Speed Over Ground
    char            pos_acc;           //!< 1 bit    : Position Accuracy
    long            longitude;         //!< 28 bits  : Longitude in 1/10000 minute
    long            latitude;          //!< 27 bits  : Latitude in 1/10000 minute
    int             cog;               //!< 12 bits  : Course Over Ground in 1/10 degree
    int             true_heading;      //!< 9 bits   : True Heading
    char            utc_sec;           //!< 6 bits   : UTC Seconds
    char            regional2;         //!< 4 bits   : Regional Bits
    char            name[21];          //!< 120 bits : Ship Name in ASCII
    unsigned char   ship_type;         //!< 8 bits   : Type of Ship and Cargo
    int             dim_bow;           //!< 9 bits   : GPS Ant. Distance from Bow
    int             dim_stern;         //!< 9 bits   : GPS Ant. Distance from Stern   
    char            dim_port;          //!< 6 bits   : GPS Ant. Distance from Port
    char            dim_starboard;     //!< 6 bits   : GPS Ant. Distance from Starboard
    char            pos_type;          //!< 4 bits   : Type of Position Fixing Device
    char            raim;              //!< 1 bit    : RAIM Flag
    char            dte;               //!< 1 bit    : DTE Flag
    char            spare;             //!< 5 bits   : Spare
    aismsg_19_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_19;


/** AIS Message 20 - Data Link Management
*/
typedef enum {
    e_aismsg_20_spare1          = 1 << 0,   //!< Spare
    e_aismsg_20_offset1         = 1 << 1,   //!< Slot Offset 1
    e_aismsg_20_slots1          = 1 << 2,   //!< Number of Slots 1
    e_aismsg_20_timeout1        = 1 << 3,   //!< Timeout in Minutes 2
    e_aismsg_20_increment1      = 1 << 4,   //!< Slot Increment 1
    e_aismsg_20_offset2         = 1 << 5,   //!< Slot Offset 2
    e_aismsg_20_slots2          = 1 << 6,   //!< Number of Slots 2
    e_aismsg_20_timeout2        = 1 << 7,   //!< Timeout in Minutes 2
    e_aismsg_20_increment2      = 1 << 8,   //!< Slot Increment 2
    e_aismsg_20_offset3         = 1 << 9,   //!< Slot Offset 3
    e_aismsg_20_slots3          = 1 << 10,  //!< Number of Slots 3
    e_aismsg_20_timeout3        = 1 << 11,  //!< Timeout in Minutes 3
    e_aismsg_20_increment3      = 1 << 12,  //!< Slot Increment 3
    e_aismsg_20_offset4         = 1 << 13,  //!< Slot Offset 4
    e_aismsg_20_slots4          = 1 << 14,  //!< Number of Slots 4
    e_aismsg_20_timeout4        = 1 << 15,  //!< Timeout in Minutes 4
    e_aismsg_20_increment4      = 1 << 16,  //!< Slot Increment 4
    e_aismsg_20_spare2          = 1 << 17,  //!< Spare
    e_aismsg_20_num_cmds        = 1 << 18,  //!< Number of commands received
} aismsg_20_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (20)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            spare1;            //!< 2 bits   : Spare
    int             offset1;           //!< 12 bits  : Slot Offset 1
    char            slots1;            //!< 4 bits   : Number of Slots 1
    char            timeout1;          //!< 3 bits   : Timeout in Minutes 2
    int             increment1;        //!< 11 bits  : Slot Increment 1
    int             offset2;           //!< 12 bits  : Slot Offset 2
    char            slots2;            //!< 4 bits   : Number of Slots 2
    char            timeout2;          //!< 3 bits   : Timeout in Minutes 2
    int             increment2;        //!< 11 bits  : Slot Increment 2
    int             offset3;           //!< 12 bits  : Slot Offset 3
    char            slots3;            //!< 4 bits   : Number of Slots 3
    char            timeout3;          //!< 3 bits   : Timeout in Minutes 3
    int             increment3;        //!< 11 bits  : Slot Increment 3
    int             offset4;           //!< 12 bits  : Slot Offset 4
    char            slots4;            //!< 4 bits   : Number of Slots 4
    char            timeout4;          //!< 3 bits   : Timeout in Minutes 4
    int             increment4;        //!< 11 bits  : Slot Increment 4
    char            spare2;            //!< 0-6 bits : Spare
    char            num_cmds;          //!< Number of commands received
    aismsg_20_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_20;


/** AIS Message 21 - Aids-to-navigation Report
*/
typedef enum {
    e_aismsg_21_aton_type       = 1 << 0,   //!< Type of AtoN
    e_aismsg_21_name            = 1 << 1,   //!< Name of AtoN in ASCII
    e_aismsg_21_pos_acc         = 1 << 2,   //!< Position Accuracy
    e_aismsg_21_longitude       = 1 << 3,   //!< Longitude in 1/10000 minutes
    e_aismsg_21_latitude        = 1 << 4,   //!< Latitude in 1/10000 minutes
    e_aismsg_21_dim_bow         = 1 << 5,   //!< GPS Ant. Distance from Bow
    e_aismsg_21_dim_stern       = 1 << 6,   //!< GPS Ant. Distance from Stern
    e_aismsg_21_dim_port        = 1 << 7,   //!< GPS Ant. Distance from Port
    e_aismsg_21_dim_starboard   = 1 << 8,   //!< GPS Ant. Distance from Starboard
    e_aismsg_21_pos_type        = 1 << 9,   //!< Type of Position Fixing Device
    e_aismsg_21_utc_sec         = 1 << 10,  //!< UTC Seconds
    e_aismsg_21_off_position    = 1 << 11,  //!< Off Position Flag
    e_aismsg_21_aton_status     = 1 << 12,  //!< AIDS to Navigation status indicator
    e_aismsg_21_raim            = 1 << 13,  //!< RAIM Flag
    e_aismsg_21_pseudo          = 1 << 14,  //!< Virtual/Pseudo AtoN Flag
    e_aismsg_21_assigned        = 1 << 15,  //!< Assigned Mode Flag
    e_aismsg_21_spare1          = 1 << 16,  //!< Spare
    e_aismsg_21_name_ext        = 1 << 17,  //!< Extended name in ASCII
    e_aismsg_21_spare2          = 1 << 18,  //!< Spare
} aismsg_21_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (21)     
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            aton_type;         //!< 5 bits   : Type of AtoN
    char            name[21];          //!< 120 bits : Name of AtoN in ASCII
    char            pos_acc;           //!< 1 bit    : Position Accuracy
    long            longitude;         //!< 28 bits  : Longitude in 1/10000 minutes
    long            latitude;          //!< 27 bits  : Latitude in 1/10000 minutes
    int             dim_bow;           //!< 9 bits   : GPS Ant. Distance from Bow
    int             dim_stern;         //!< 9 bits   : GPS Ant. Distance from Stern
    char            dim_port;          //!< 6 bits   : GPS Ant. Distance from Port
    char            dim_starboard;     //!< 6 bits   : GPS Ant. Distance from Starboard
    char            pos_type;          //!< 4 bits   : Type of Position Fixing Device
    char            utc_sec;           //!< 6 bits   : UTC Seconds
    char            off_position;      //!< 1 bit    : Off Position Flag
    unsigned char   aton_status;       //!< 8 bits   : AIDS to Navigation status indicator
    char            raim;              //!< 1 bit    : RAIM Flag
    char            pseudo;            //!< 1 bit    : Virtual/Pseudo AtoN Flag
    char            assigned;          //!< 1 bit    : Assigned Mode Flag
    char            spare1;            //!< 1 bit    : Spare
    char            name_ext[16];      //!< 0-84 bits : Extended name in ASCII
    char            spare2;            //!< 0-6 bits : Spare
    aismsg_21_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_21;


/** AIS Message 22 - Channel Management

    If the message is for a geographic area its 2 corners are
    defined by the NE and SW positions. If it is an assigned
    message the destination MMSI will be in addressed_1 and
    addressed_2.
*/
typedef enum {
    e_aismsg_22_spare1          = 1 << 0,   //!< Spare
    e_aismsg_22_channel_a       = 1 << 1,   //!< M.1084 Channel A Frequency
    e_aismsg_22_channel_b       = 1 << 2,   //!< M.1084 Channel B Frequency
    e_aismsg_22_txrx_mode       = 1 << 3,   //!< TX/RX Mode
    e_aismsg_22_power           = 1 << 4,   //!< Power Level
    e_aismsg_22_NE_longitude    = 1 << 5,   //!< Longitude in 1/10000 minutes
    e_aismsg_22_NE_latitude     = 1 << 6,   //!< Latitude in 1/10000 minutes
    e_aismsg_22_addressed_1     = 1 << 7,   //!< Destination MMSI 1
    e_aismsg_22_SW_longitude    = 1 << 8,   //!< Longitude in 1/10000 minutes
    e_aismsg_22_SW_latitude     = 1 << 9,   //!< Latitude in 1/10000 minutes
    e_aismsg_22_addressed_2     = 1 << 10,  //!< Destination MMSI 2
    e_aismsg_22_addressed       = 1 << 11,  //!< Addressed flag
    e_aismsg_22_bw_a            = 1 << 12,  //!< Channel A Bandwidth
    e_aismsg_22_bw_b            = 1 << 13,  //!< Channel B Bandwidth
    e_aismsg_22_tz_size         = 1 << 14,  //!< Transitional Zone size
    e_aismsg_22_spare2          = 1 << 15,  //!< Spare
} aismsg_22_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (22)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            spare1;            //!< 2 bits   : Spare
    int             channel_a;         //!< 12 bits  : M.1084 Channel A Frequency
    int             channel_b;         //!< 12 bits  : M.1084 Channel B Frequency
    char            txrx_mode;         //!< 4 bits   : TX/RX Mode
    char            power;             //!< 1 bit    : Power Level
    long            NE_longitude;      //!< 18 bits  : Longitude in 1/10000 minutes
    long            NE_latitude;       //!< 17 bits  : Latitude in 1/10000 minutes
    unsigned long   addressed_1;       //!< 30 bits  : Destination MMSI 1
    long            SW_longitude;      //!< 18 bits  : Longitude in 1/1000 minutes
    long            SW_latitude;       //!< 17 bits  : Latitude in 1/1000 minutes
    unsigned long   addressed_2;       //!< 30 bits  : Destination MMSI 2
    char            addressed;         //!< 1 bit    : Addressed flag
    char            bw_a;              //!< 1 bit    : Channel A Bandwidth
    char            bw_b;              //!< 1 bit    : Channel B Bandwidth
    char            tz_size;           //!< 3 bits   : Transitional Zone size
    unsigned long   spare2;            //!< 23 bits  : Spare
    aismsg_22_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_22;


/** AIS Message 23 - Group Assignment Command

    The geographic area is defined by 2 corners, stored in 
    the NE and SW positions. 
*/
typedef enum {
    e_aismsg_23_spare1          = 1 << 0,   //!< Spare
    e_aismsg_23_NE_longitude    = 1 << 1,   //!< Longitude in 1/10000 minutes
    e_aismsg_23_NE_latitude     = 1 << 2,   //!< Latitude in 1/10000 minutes
    e_aismsg_23_SW_longitude    = 1 << 3,   //!< Longitude in 1/10000 minutes
    e_aismsg_23_SW_latitude     = 1 << 4,   //!< Latitude in 1/10000 minutes
    e_aismsg_23_station_type    = 1 << 5,   //!< Station Type
    e_aismsg_23_ship_type       = 1 << 6,   //!< Type of Ship and Cargo
    e_aismsg_23_spare2          = 1 << 7,   //!< Spare
    e_aismsg_23_txrx_mode       = 1 << 8,   //!< TX/RX Mode
    e_aismsg_23_report_interval = 1 << 9,   //!< Reporting Interval from IEC 62287 Table 17
    e_aismsg_23_quiet_time      = 1 << 10,  //!< Quiet Time in Minutes
    e_aismsg_23_spare3          = 1 << 11,  //!< Spare
} aismsg_23_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (23)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            spare1;            //!< 2 bits   : Spare
    long            NE_longitude;      //!< 18 bits  : Longitude in 1/10000 minutes
    long            NE_latitude;       //!< 17 bits  : Latitude in 1/10000 minutes
    long            SW_longitude;      //!< 18 bits  : Longitude in 1/10000 minutes
    long            SW_latitude;       //!< 17 bits  : Latitude in 1/10000 minutes
    char            station_type;      //!< 4 bits   : Station Type
    unsigned char   ship_type;         //!< 8 bits   : Type of Ship and Cargo
    unsigned long   spare2;            //!< 22 bits  : Spare
    char            txrx_mode;         //!< 2 bits   : TX/RX Mode
    char            report_interval;   //!< 4 bits   : Reporting Interval from IEC 62287 Table 17
    char            quiet_time;        //!< 4 bits   : Quiet Time in Minutes
    char            spare3;            //!< 6 bits   : Spare
    aismsg_23_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_23;


/** AIS Message 24 - Class B CS Static Data Report

    Message 24 is a 2 part message, 24A with the name and
    24B with the dimensions, etc. This structure is used
    to hold the results.
*/
typedef enum {
    e_aismsg_24_part_number     = 1 << 0,   //!< Part Number
    e_aismsg_24_name            = 1 << 1,   //!< Ship Name in ASCII from Message 24A
    e_aismsg_24_ship_type       = 1 << 2,   //!< Type of Ship and Cargo from Message 24B
    e_aismsg_24_vendor_id       = 1 << 3,   //!< Vendor ID in ASCII
    e_aismsg_24_callsign        = 1 << 4,   //!< Callsign in ASCII
    e_aismsg_24_dim_bow         = 1 << 5,   //!< GPS Ant. Distance from Bow
    e_aismsg_24_dim_stern       = 1 << 6,   //!< GPS Ant. Distance from Stern
    e_aismsg_24_dim_port        = 1 << 7,   //!< GPS Ant. Distance from Port
    e_aismsg_24_dim_starboard   = 1 << 8,   //!< GPS Ant. Distance from Starboard
    e_aismsg_24_spare           = 1 << 9,   //!< Spare
    e_aismsg_24_flags           = 1 << 10,  //!< A/B flags - A = 1  B = 2  Both = 3  
} aismsg_24_invalidity_mask;

typedef struct {
    char            msgid;             //!< 6 bits   : MessageID (24)
    char            repeat;            //!< 2 bits   : Repeated
    unsigned long   userid;            //!< 30 bits  : UserID / MMSI
    char            part_number;       //!< 2 bits   : Part Number

    //!< Message 24A 
    char            name[21];          //!< 120 bits : Ship Name in ASCII

    //!< Message 24B 
    unsigned char   ship_type;         //!< 8 bits   : Type of Ship and Cargo
    char            vendor_id[8];      //!< 42 bits  : Vendor ID in ASCII
    char            callsign[8];       //!< 42 bits  : Callsign in ASCII
    int             dim_bow;           //!< 9 bits   : GPS Ant. Distance from Bow
    int             dim_stern;         //!< 9 bits   : GPS Ant. Distance from Stern
    char            dim_port;          //!< 6 bits   : GPS Ant. Distance from Port
    char            dim_starboard;     //!< 6 bits   : GPS Ant. Distance from Starboard
    char            spare;             //!< 6 bits   : Spare

    char            flags;             //!< A/B flags - A = 1  B = 2  Both = 3  
    aismsg_24_invalidity_mask mask;    //!< Data validity mask. TRUE means that data is incorrect.
} aismsg_24;


/** ETA, Seaway and IMO UTC Timetag
*/
typedef struct {
    char            month;             //!< 4 bits   : Month
    char            day;               //!< 5 bits   : Day
    char            hours;             //!< 5 bits   : UTC Hours
    char            minutes;           //!< 6 bits   : UTC Minutes
} timetag;


/* ------------------------------------------------------------------------ */
/** ais_state the state for the Message Parser

    It keeps track partial messages until a complete message has been
    received and it holds the sixbit state for extacting bits from the
    message.
*/
/* ------------------------------------------------------------------------ */
typedef struct {
    unsigned char msgid;               //!< Message ID 0-31
    unsigned int  sequence;            //!< VDM message sequence number
    unsigned int  total;               //!< Total # of parts for the message
    unsigned int  num;                 //!< Number of the last part stored
    char          channel;             //!< AIS Channel character
    sixbit        six_state;           //!< sixbit parser state
} ais_state;


/* ------------------------------------------------------------------------ */
/** binary_state the state for the Seaway/IMO Message Parser

	Holds the DAC, FI, msgid and the message bits in six_state
	Used for processing the data portion of a binary message
*/
/* ------------------------------------------------------------------------ */
typedef struct {
    int dac;                           //!< DAC
    char fi;                           //!< FI
    char spare;                        //!< 2 bits Spare
    char msgid;                        //!< 6 bits Message ID 0-31
    sixbit        six_state;           //!< sixbit parser state
} binary_state;


/* Prototypes */
int __stdcall get_timetag( sixbit *state, timetag *datetime );
void __stdcall conv_sign( unsigned int sign_bit, int *value );
char __stdcall ais2ascii( char value );
int __stdcall pos2ddd( long latitude, long longitude, double *lat_dd, double *long_ddd );
int __stdcall pos2dmm( long latitude, long longitude, short *lat_dd, double *lat_min, short *long_ddd, double *long_min );
int __stdcall conv_pos( long *latitude, long *longitude );
int __stdcall assemble_vdm( ais_state *state, char *str );
int __stdcall parse_ais_1( ais_state *state, aismsg_1 *result );
int __stdcall parse_ais_2( ais_state *state, aismsg_2 *result );
int __stdcall parse_ais_3( ais_state *state, aismsg_3 *result );
int __stdcall parse_ais_4( ais_state *state, aismsg_4 *result );
int __stdcall parse_ais_5( ais_state *state, aismsg_5 *result );
int __stdcall parse_ais_6( ais_state *state, aismsg_6 *result );
int __stdcall parse_ais_7( ais_state *state, aismsg_7 *result );
int __stdcall parse_ais_8( ais_state *state, aismsg_8 *result );
int __stdcall parse_ais_9( ais_state *state, aismsg_9 *result );
int __stdcall parse_ais_10( ais_state *state, aismsg_10 *result );
int __stdcall parse_ais_11( ais_state *state, aismsg_11 *result );
int __stdcall parse_ais_12( ais_state *state, aismsg_12 *result );
int __stdcall parse_ais_13( ais_state *state, aismsg_13 *result );
int __stdcall parse_ais_14( ais_state *state, aismsg_14 *result );
int __stdcall parse_ais_15( ais_state *state, aismsg_15 *result );
int __stdcall parse_ais_16( ais_state *state, aismsg_16 *result );
int __stdcall parse_ais_17( ais_state *state, aismsg_17 *result );
int __stdcall parse_ais_18( ais_state *state, aismsg_18 *result );
int __stdcall parse_ais_19( ais_state *state, aismsg_19 *result );
int __stdcall parse_ais_20( ais_state *state, aismsg_20 *result );
int __stdcall parse_ais_21( ais_state *state, aismsg_21 *result );
int __stdcall parse_ais_22( ais_state *state, aismsg_22 *result );
int __stdcall parse_ais_23( ais_state *state, aismsg_23 *result );
int __stdcall parse_ais_24( ais_state *state, aismsg_24 *result );
