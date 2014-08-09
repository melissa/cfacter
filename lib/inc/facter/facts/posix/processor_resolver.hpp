/**
 * @file
 * Declares the POSIX processor fact resolver.
 */
#ifndef FACTER_FACTS_POSIX_PROCESSOR_RESOLVER_HPP_
#define FACTER_FACTS_POSIX_PROCESSOR_RESOLVER_HPP_

#include "../resolver.hpp"
#include <sys/utsname.h>

namespace facter { namespace facts { namespace posix {

    /**
     * Responsible for resolving processor-related facts.
     */
    struct processor_resolver : resolver
    {
        /**
         * Constructs the processor_resolver.
         */
        processor_resolver();

     protected:
        /**
         * Called to resolve all facts the resolver is responsible for.
         * @param facts The fact collection that is resolving facts.
         */
        virtual void resolve_facts(collection& facts);
        /**
         * Called to resolve the hardware ISA fact.
         * @param facts The fact collection that is resolving facts.
         * @param name The result of the uname call.
         */
        virtual void resolve_hardware_isa(collection& facts, utsname const& name);
        /**
         * Called to resolve the hardware model fact.
         * @param facts The fact collection that is resolving facts.
         * @param name The result of the uname call.
         */
        virtual void resolve_hardware_model(collection& facts, utsname const& name);
        /**
         * Called to resolve the hardware architecture fact.
         * @param facts The fact collection that is resolving facts.
         */
        virtual void resolve_architecture(collection& facts);
        /**
         * Called to resolve processor count, physical processor count, and description facts.
         * @param facts The fact collection that is resolving facts.
         */
        virtual void resolve_processors(collection& facts);
        /**
         * Called to resolve the processors structured fact.
         * @param facts The fact collection that is resolving facts.
         */
        virtual void resolve_structured_processors(collection& facts) = 0;
    };

}}}  // namespace facter::facts::posix

#endif  // FACTER_FACTS_POSIX_PROCESSOR_RESOLVER_HPP_