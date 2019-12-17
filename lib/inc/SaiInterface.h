#pragma once

extern "C" {
#include "sai.h"
#include "saimetadata.h"
}

#define SAIREDIS_SAIINTERFACE_DECLARE_REMOVE_ENTRY(ot)  \
    virtual sai_status_t remove(                        \
            _In_ const sai_ ## ot ## _t* ot) = 0;

namespace sairedis
{
    class SaiInterface
    {
        public:

            SaiInterface() = default;

            virtual ~SaiInterface() = default;

        public: // remove

            virtual sai_status_t remove(
                    _In_ sai_object_type_t objectType,
                    _In_ sai_object_id_t objectId) = 0;

            SAIREDIS_SAIINTERFACE_DECLARE_REMOVE_ENTRY(fdb_entry);
            SAIREDIS_SAIINTERFACE_DECLARE_REMOVE_ENTRY(inseg_entry);
            SAIREDIS_SAIINTERFACE_DECLARE_REMOVE_ENTRY(ipmc_entry);
            SAIREDIS_SAIINTERFACE_DECLARE_REMOVE_ENTRY(l2mc_entry);
            SAIREDIS_SAIINTERFACE_DECLARE_REMOVE_ENTRY(mcast_fdb_entry);
            SAIREDIS_SAIINTERFACE_DECLARE_REMOVE_ENTRY(neighbor_entry);
            SAIREDIS_SAIINTERFACE_DECLARE_REMOVE_ENTRY(route_entry);
            SAIREDIS_SAIINTERFACE_DECLARE_REMOVE_ENTRY(nat_entry);
    };
}
