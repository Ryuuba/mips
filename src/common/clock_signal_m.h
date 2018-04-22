//
// Generated file, do not edit! Created by nedtool 5.2 from common/clock_signal.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __CLOCK_SIGNAL_M_H
#define __CLOCK_SIGNAL_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0502
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>common/clock_signal.msg:1</tt> by nedtool.
 * <pre>
 * message ClockSignal
 * {
 *     bool level;
 * }
 * </pre>
 */
class ClockSignal : public ::omnetpp::cMessage
{
  protected:
    bool level;

  private:
    void copy(const ClockSignal& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ClockSignal&);

  public:
    ClockSignal(const char *name=nullptr, short kind=0);
    ClockSignal(const ClockSignal& other);
    virtual ~ClockSignal();
    ClockSignal& operator=(const ClockSignal& other);
    virtual ClockSignal *dup() const override {return new ClockSignal(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual bool getLevel() const;
    virtual void setLevel(bool level);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ClockSignal& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ClockSignal& obj) {obj.parsimUnpack(b);}


#endif // ifndef __CLOCK_SIGNAL_M_H
