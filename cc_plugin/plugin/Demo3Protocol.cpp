// Generated by commsdsl2comms v3.6.2

#include "Demo3Protocol.h"

#include <cassert>
#include "comms_champion/ProtocolBase.h"
#include "cc_plugin/frame/Frame.h"
#include "cc_plugin/frame/FrameTransportMessage.h"

namespace cc = comms_champion;

namespace demo3
{

namespace cc_plugin
{

namespace plugin
{

class Demo3ProtocolImpl : public
    cc::ProtocolBase<
        demo3::cc_plugin::frame::Frame,
        demo3::cc_plugin::frame::FrameTransportMessage
    >
{
    using Base =
        cc::ProtocolBase<
            demo3::cc_plugin::frame::Frame,
            demo3::cc_plugin::frame::FrameTransportMessage
        >;
public:
    friend class demo3::cc_plugin::plugin::Demo3Protocol;

    Demo3ProtocolImpl() = default;
    virtual ~Demo3ProtocolImpl() = default;

    int getVersion() const
    {
        return m_version;
    }
    
    void setVersion(int value)
    {
        m_version = value;
        updateFrame();
    }
    
protected:
    virtual const QString& nameImpl() const override
    {
        static const QString Str("demo3");
        return Str;
    }

    virtual MessagesList createAllMessagesImpl() override
    {
        auto list = Base::createAllMessagesImpl();
        for (auto& mPtr : list) {
            updateMessageWithVersion(*mPtr);
        }
        return list;
    }
    
    virtual cc::MessagePtr createMessageImpl(const QString& idAsString, unsigned idx) override
    {
        auto mPtr = Base::createMessageImpl(idAsString, idx);
        updateMessageWithVersion(*mPtr);
        return mPtr;
    }
    
    
    using Base::createInvalidMessageImpl;
    using Base::createRawDataMessageImpl;
    using Base::createExtraInfoMessageImpl;

private:
    void updateMessageWithVersion(cc::Message& msg)
    {
        assert(dynamic_cast<demo3::cc_plugin::Message*>(&msg) != nullptr);
        static_assert(demo3::cc_plugin::Message::hasVersionInTransportFields(),
            "Interface type is expected to has version in transport fields");
        static const std::size_t VersionIdx = 
            demo3::cc_plugin::Message::InterfaceOptions::VersionInExtraTransportFields;
        auto& castedMsg = static_cast<demo3::cc_plugin::Message&>(msg);
        std::get<VersionIdx>(castedMsg.transportFields()).value() =
            static_cast<demo3::cc_plugin::Message::VersionType>(m_version);
        castedMsg.refresh();
        updateMessage(msg);
    }

    void updateFrame()
    {
        auto& layer_version = protocolStack().layer_version();
        using LayerType_Version = typename std::decay<decltype(layer_version)>::type;
        layer_version.pseudoField().value() =
            static_cast<LayerType_Version::Field::ValueType>(m_version);
        
    }
    
    int m_version = 5U;

};

Demo3Protocol::Demo3Protocol()
  : m_pImpl(new Demo3ProtocolImpl())
{
}

Demo3Protocol::~Demo3Protocol() = default;

int Demo3Protocol::getVersion() const
{
    return m_pImpl->getVersion();
}

void Demo3Protocol::setVersion(int value)
{
    m_pImpl->setVersion(value);
}

const QString& Demo3Protocol::nameImpl() const
{
    return m_pImpl->name();
}

Demo3Protocol::MessagesList Demo3Protocol::readImpl(const cc::DataInfo& dataInfo, bool final)
{
    return m_pImpl->read(dataInfo, final);
}

cc::DataInfoPtr Demo3Protocol::writeImpl(cc::Message& msg)
{
    return m_pImpl->write(msg);
}

Demo3Protocol::MessagesList Demo3Protocol::createAllMessagesImpl()
{
    return m_pImpl->createAllMessages();
}

cc::MessagePtr Demo3Protocol::createMessageImpl(const QString& idAsString, unsigned idx)
{
    return static_cast<cc::Protocol*>(m_pImpl.get())->createMessage(idAsString, idx);
}

Demo3Protocol::UpdateStatus Demo3Protocol::updateMessageImpl(cc::Message& msg)
{
    return m_pImpl->updateMessage(msg);
}

cc::MessagePtr Demo3Protocol::cloneMessageImpl(const cc::Message& msg)
{
    return m_pImpl->cloneMessage(msg);
}

cc::MessagePtr Demo3Protocol::createInvalidMessageImpl()
{
    return m_pImpl->createInvalidMessageImpl();
}

cc::MessagePtr Demo3Protocol::createRawDataMessageImpl()
{
    return m_pImpl->createRawDataMessageImpl();
}

cc::MessagePtr Demo3Protocol::createExtraInfoMessageImpl()
{
    return m_pImpl->createExtraInfoMessageImpl();
}

} // namespace plugin

} // namespace cc_plugin

} // namespace demo3


