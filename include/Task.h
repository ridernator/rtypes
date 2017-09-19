#pragma once

namespace rtypes {

    class Task {
    public:
        virtual ~Task();

        virtual void run() = 0;
    };
}