//
// Generated file, do not edit! Created by nedtool 5.2 from common/ctrl_signal.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __CTRL_SIGNAL_M_H
#define __CTRL_SIGNAL_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0502
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>common/ctrl_signal.msg:1</tt> by nedtool.
 * <pre>
 * message CtrlSignal
 * {
 *     bool signal[];
 * }
 * </pre>
 */
class CtrlSignal : public ::omnetpp::cMessage
{
  protected:
    bool *signal; // array ptr
    unsigned int signal_arraysize;

  private:
    void copy(const CtrlSignal& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const CtrlSignal&);

  public:
    CtrlSignal(const char *name=nullptr, short kind=0);
    CtrlSignal(const CtrlSignal& other);
    virtual ~CtrlSignal();
    CtrlSignal& operator=(const CtrlSignal& other);
    virtual CtrlSignal *dup() const override {return new CtrlSignal(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual void setSignalArraySize(unsigned int size);
    virtual unsigned int getSignalArraySize() const;
    virtual bool getSignal(unsigned int k) const;
    virtual void setSignal(unsigned int k, bool signal);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const CtrlSignal& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, CtrlSignal& obj) {obj.parsimUnpack(b);}


#endif // ifndef __CTRL_SIGNAL_M_H

