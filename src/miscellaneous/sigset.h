//
// Created by luojiayi on 5/9/17.
//

#ifndef ROOKIE_MISCELLANEOUS_SIGAL_SET_H
#define ROOKIE_MISCELLANEOUS_SIGAL_SET_H
#include <csignal>

namespace rookie{
    class SigSet{
    public:
        SigSet():the_set_(){ clear(); };
        SigSet(sigset_t target):the_set_(target){};
        sigset_t getSigSet() const { return the_set_; };
        void clear(){ sigemptyset(&the_set_); };
        bool contains(int target_signal_num) const { return sigismember( &the_set_, target_signal_num ); };
        void add(int target_signal_num) { sigaddset(&the_set_, target_signal_num); };
        void remove(int target_signal_num) { sigdelset(&the_set_, target_signal_num); };

    private:
        sigset_t the_set_;
    };
}

#endif //ROOKIE_SIGAL_SET_H
