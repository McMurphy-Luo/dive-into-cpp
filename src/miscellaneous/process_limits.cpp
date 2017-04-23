//
// Created by luojiayi on 4/23/17.
//

#include "process_limits.h"
#include <memory>
#include <map>

namespace rookie{

    namespace{
        typedef std::map<ProcessLimits::LimitType, std::string> limit_description_map_t;
        limit_description_map_t *limit_description_map = nullptr;
        const limit_description_map_t *getLimitDescriptionMap(){
            if (limit_description_map) return limit_description_map;
            limit_description_map = new limit_description_map_t;

            limit_description_map->insert(
                    std::make_pair<ProcessLimits::LimitType, std::string>(
                            std::move(ProcessLimits::LimitType::kAS),
                            "asdfsadf"
                    )
            );
            return limit_description_map;
        };
    }


    std::string ProcessLimits::getLimitDescription(LimitType of_which) {
        const limit_description_map_t *limit_description_map = getLimitDescriptionMap();
        const std::string &stored_description = limit_description_map->at(of_which);
        return stored_description;
    }
};
