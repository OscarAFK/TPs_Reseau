#pragma once

#include <map>
#include <frameworkTP3.h>
#include <NetworkObject.h>
#include <optional>
#include <vector>
#include "LinkingContext.h"
#include <unordered_set>
#include <ClassRegistry.h>

namespace uqac {
    namespace replication {

        enum class PacketType : uint8_t {
            Hello = 0x00,
            Sync = 0x01,
            Bye = 0x02,
            PacketType_Max
        };

        class ReplicationManager {
        public:
            ReplicationManager(LinkingContext* linkingContext) : m_linkingContext(linkingContext) {};
            ~ReplicationManager() = default;

            void Update(std::vector<utilsTP3::NetworkObject*> alloR, serialization::Serializer* s, serialization::Deserializer* d);
            void SendWorld(std::vector<utilsTP3::NetworkObject*> alloR, serialization::Serializer* s);
            void RecvWorld(serialization::Deserializer* d);

        private:
            void SerializeObject(serialization::Serializer* s, utilsTP3::NetworkObject* oR);
            void DeserializeObject(serialization::Deserializer* d);

            std::unordered_set<utilsTP3::NetworkObject*> m_objectsReplicated;
            LinkingContext* m_linkingContext;
        };
    }
}