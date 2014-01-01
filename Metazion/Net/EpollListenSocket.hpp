#ifndef MZ_NET_EPOLLLISTENSOCKET_HPP
#define MZ_NET_EPOLLLISTENSOCKET_HPP

#include "Metazion/Net/NetInclude.hpp"

#if defined(MZ_PLATFORM_LINUX)

#include <Metazion/Share/Memory/PieceBuffer.hpp>
#include <Metazion/Share/Memory/RingBuffer.hpp>
#include "Metazion/Net/EpollSocket.hpp"

DECL_NAMESPACE_MZ_NET_BEGIN

class EpollListenSocket : public EpollSocket {
    DISALLOW_COPY_AND_ASSIGN(EpollListenSocket)

public:
    EpollListenSocket();

    virtual ~EpollListenSocket();

public: // @override
    void Reset();

    void OnStarted();

    bool IsClosing();

public:
    bool Listen(const char* ip, int port);

private: // @override
    void Input();

    void Output();

protected:
    Host m_localHost;
};

DECL_NAMESPACE_MZ_NET_END

#endif // MZ_PLATFORM_LINUX

#endif // MZ_NET_EPOLLLISTENSOCKET_HPP
